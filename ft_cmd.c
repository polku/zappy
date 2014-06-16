/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 17:20:31 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/16 14:42:14 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_avance(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)buff;
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_droite(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)buff;
	p->dir = (p->dir + 1) % 3;
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_gauche(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)buff;
	p->dir = (p->dir - 1 == 0 ? 4 : p->dir - 1);
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_voir(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}

int		ft_inv(t_server *serv, t_plyr *p, char *buff)
{
	char	tmp[BUFF_SZ];

	(void)buff;
	sprintf(tmp, "{nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d}\n",
			p->inv[FOOD], p->inv[LINEMATE], p->inv[DERAUMERE], p->inv[SIBUR],
			p->inv[MENDIANE], p->inv[PHIRAS], p->inv[THYSTAME]);
	ft_send(serv, p->sock, tmp);
	return (0);
}

int		ft_take(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}

int		ft_put(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}

int		ft_exp(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}

int		ft_broadcast(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)buff;
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_incantation(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}

int		ft_fork(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)buff;
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_nb_conn(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}

int		ft_unknown(t_server *serv, t_plyr *p, char *buff)
{
	(void)serv;
	(void)p;
	(void)buff;
	return (0);
}
