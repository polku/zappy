/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 10:49:37 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/25 11:00:42 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_recv(t_server *serv, t_plyr *p)
{
	int		rd;

	rd = recv(p->sock, serv->buff_rd, BUFF_SZ - 1, 0);
	if (rd == 0)
	{
		ft_del_plyr(serv, p);
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
	FD_SET(serv->sock_graph, &serv->rd_set);
	tmp = serv->plyr;
	while (tmp)
	{
		FD_SET(tmp->sock, &serv->rd_set);
		tmp = tmp->next;
	}
	return (0);
}

int		ft_loop(t_server *serv)
{
	static struct timeval	delay = { 0, 0 };
	struct timeval			time;
	t_plyr					*tmp;

	tmp = serv->plyr;
	while (tmp)
	{
		if (FD_ISSET(tmp->sock, &serv->rd_set))
		{
			if (ft_recv(serv, tmp) == -1)
				return (-1);
			ft_save_cmd(serv, tmp, serv->buff_rd);
		}
		ft_exec_cmd(serv, tmp);
		if (delay.tv_usec == 0)
			tmp->pv--;
		tmp = tmp->next;
	}
	gettimeofday(&time, NULL);
	delay.tv_usec = (delay.tv_usec == 0 ?
		SEC / serv->speed : delay.tv_usec - (time.tv_usec - delay.tv_usec));
	return (0);
}
