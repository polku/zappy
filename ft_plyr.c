/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plyr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 11:59:58 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/24 16:14:55 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_add_plyr(t_server *serv)
{
	int					sz;
	struct sockaddr_in	sai;
	int					sock;
	static int			id = 0;
	t_team				team;

	sz = sizeof(sai);
	sock = accept(serv->sock, (struct sockaddr *)&sai, (socklen_t *)&sz);
	if (sock == -1)
		ft_error("Error connection");
	ft_send(serv, sock, "BIENVENUE\n");
	serv->fd_max = (sock > serv->fd_max ? sock : serv->fd_max);
	ft_putendl("Connection etablished");

	serv->plyr = ft_add_plist(sock, id, serv->plyr); // + nom team
	id++;
	// recup nom equipe, chk nb _conn, auth ou pas conn , send dim md
	return (0);
}

int		ft_del_plyr(t_server *serv, t_plyr *p)
{
	close(p->sock);
	serv->plyr = ft_del_plist(serv->plyr, p);
	return (0);
}

int		ft_cmd(char *buff)
{
	if (ft_strncmp(buff, "avance", 6) == 0)
		return (AVANCE);
	else if (ft_strncmp(buff, "droite", 6) == 0)
		return (DROITE);
	else if (ft_strncmp(buff, "gauche", 6) == 0)
		return (GAUCHE);
	else if (ft_strncmp(buff, "voir", 4) == 0)
		return (VOIR);
	else if (ft_strncmp(buff, "inventaire", 10) == 0)
		return (INV);
	else if (ft_strncmp(buff, "prend ", 6) == 0)
		return (PREND);
	else if (ft_strncmp(buff, "pose ", 5) == 0)
		return (POSE);
	else if (ft_strncmp(buff, "expulse", 7) == 0)
		return (EXP);
	else if (ft_strncmp(buff, "broadcast ", 10) == 0)
		return (BROADCAST);
	else if (ft_strncmp(buff, "incantation", 11) == 0)
		return (INCANTATION);
	else if (ft_strncmp(buff, "fork", 4) == 0)
		return (FORK);
	else if (ft_strncmp(buff, "connect_nbr", 11) == 0)
		return (CONN_NBR);
	return (-1);
}

int		ft_save_cmd(t_server *serv, t_plyr *p, char *buff)
{
	int		chk;
	char	**split;

	split = ft_strsplit(buff, ' ');
	chk = ft_cmd(split[0]);
	if (p->nb_cmds < 10 && chk != -1)
	{
		p->cmd = ft_add_cmd(p->cmd, split[0], split[1]);
		p->nb_cmds++;
		return (0);
	}
	else
		return (ft_unknown(serv, p, buff));
}

int		ft_exec_cmd(t_server *serv, t_plyr *p)
{
	struct timeval	time;
	t_cmd			*tmp;
	t_func			func[NB_CMD];
	int				delay[NB_CMD] = { 7, 7, 7, 7, 1, 7, 7, 7, 7, 300, 42, 0 };

	gettimeofday(&time, NULL);
	tmp = p->cmd;
	if (tmp)
	{
		if (time.tv_usec > tmp->end.tv_usec)
		{
			func[tmp->type](serv, p, tmp->arg);
			tmp->next->end.tv_usec = time.tv_usec + delay[tmp->type] * SEC;
			p->cmd = ft_del_cmd(tmp);
			p->nb_cmds--;
		}
	}
	return (0);
}
