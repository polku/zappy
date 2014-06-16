/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 10:49:37 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/16 11:56:25 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_recv(t_server *serv, t_plyr *p)
{
	int		rd;

	rd = recv(p->sock, serv->buff_rd, BUFF_SZ - 1, 0);
	if (rd == 0)
	{
//		del_plyr(serv, p);
		return (-1);
	}
	serv->buff_rd[rd] = '\0';
	return (0);
}

int		ft_fdset(t_server *serv)
{
	t_plyr	*tmp;

	FD_ZERO(&serv->rd_set);
	FD_SET(serv->sock, &serv->rd_set);
	tmp = serv->plyr;
	while (tmp)
	{
		FD_SET(tmp->sock, &serv->rd_set);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_fdisset(t_server *serv)
{
	t_plyr	*tmp;

	tmp = serv->plyr;
	while (tmp)
	{
		if (FD_ISSET(tmp->sock, &serv->rd_set))
		{
			if (ft_recv(serv, tmp) == -1)
				return (-1);
			ft_cmd(serv, tmp, serv->buff_rd);
		}
		tmp = tmp->next;
	}
	return (0);
}

int		ft_cmd(t_server *serv, t_plyr *p, char *buff)
{
	if (ft_strcmp(buff, "avance\n") == 0)
		return (ft_avance(serv, p, buff));
	else if (ft_strcmp(buff, "droite\n") == 0)
		return (ft_droite(serv, p, buff));
	else if (ft_strcmp(buff, "gauche\n") == 0)
		return (ft_gauche(serv, p, buff));
	else if (ft_strcmp(buff, "voir\n") == 0)
		return (ft_voir(serv, p, buff));
	else if (ft_strcmp(buff, "inventaire\n") == 0)
		return (ft_inv(serv, p, buff));
	else if (ft_strcmp(buff, "prend\n") == 0)
		return (ft_take(serv, p, buff));
	else if (ft_strcmp(buff, "pose\n") == 0)
		return (ft_put(serv, p, buff));
	else if (ft_strcmp(buff, "expulse\n") == 0)
		return (ft_exp(serv, p, buff));
	else if (ft_strcmp(buff, "broadcast\n") == 0)
		return (ft_broadcast(serv, p, buff));
	else if (ft_strcmp(buff, "incantation\n") == 0)
		return (ft_incantation(serv, p, buff));
	else if (ft_strcmp(buff, "fork\n") == 0)
		return (ft_fork(serv, p, buff));
	else if (ft_strcmp(buff, "connect_nbr\n") == 0)
		return (ft_nb_conn(serv, p, buff));
	return (ft_unknown(serv, p, buff));
}
