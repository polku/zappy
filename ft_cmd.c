/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 17:20:31 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/25 11:05:44 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_avance(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	if (p->dir == N)
		p->y = (p->y == 0 ? p->y - 1 : serv->map_hgt);
	if (p->dir == S)
		p->y = (p->y + 1) % serv->map_hgt;
	if (p->dir == E)
		p->x = (p->x + 1) % serv->map_width;
	if (p->dir == W)
		p->x = (p->x == 0 ? p->x - 1 : serv->map_width);
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_droite(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	p->dir = (p->dir + 1) % 3;
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_gauche(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	p->dir = (p->dir - 1 == 0 ? 4 : p->dir - 1);
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_voir(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	ft_send(serv, p->sock, "ko\n");
	return (0);
}

int		ft_inv(t_server *serv, t_plyr *p, char *arg)
{
	char	tmp[ARG_SZ];

	(void)arg;
	sprintf(tmp, "{nourriture %d, linemate %d, deraumere %d, sibur %d, mendiane %d, phiras %d, thystame %d}\n",
			p->inv[FOOD], p->inv[LINEMATE], p->inv[DERAUMERE], p->inv[SIBUR],
			p->inv[MENDIANE], p->inv[PHIRAS], p->inv[THYSTAME]);
	ft_send(serv, p->sock, tmp);
	return (0);
}
