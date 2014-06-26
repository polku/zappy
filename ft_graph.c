/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 15:32:37 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/26 13:06:56 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_conn_graph(t_server *serv)
{
	int					sz;
	struct sockaddr_in	sai;

	sz = sizeof(sai);
	serv->sock_graph = accept(serv->sock_conn_graph,
						(struct sockaddr *)&sai, (socklen_t *)&sz);
	if (serv->sock_graph == -1)
		ft_error("Error connection");
	ft_send(serv, serv->sock_graph, "BIENVENUE\n");
	recv(serv->sock_graph, serv->buff_rd, BUFF_SZ, 0);
	serv->fd_max = (serv->sock_graph > serv->fd_max ?
					serv->sock_graph : serv->fd_max);
	ft_putendl("Graphic connection etablished");
	ft_msz(serv, serv->buff_rd);
	return (0);
}

int		ft_graph(t_server *serv, char *buff)
{
	if (ft_strcmp(buff, "msz\n"))
		return (ft_msz(serv, buff));
	if (ft_strcmp(buff, "bct\n"))
		return (ft_bct(serv, buff));
	if (ft_strcmp(buff, "mct\n"))
		return (ft_mct(serv, buff));
	if (ft_strcmp(buff, "tna\n"))
		return (ft_tna(serv, buff));
	if (ft_strcmp(buff, "sgt\n"))
		return (ft_sgt(serv, buff));
	if (ft_strncmp(buff, "ppo ", 4))
		return (ft_ppo(serv, buff));
	if (ft_strncmp(buff, "plv ", 4))
		return (ft_plv(serv, buff));
	if (ft_strncmp(buff, "pin ", 4))
		return (ft_pin(serv, buff));
	if (ft_strncmp(buff, "sst ", 4))
		return (ft_sst(serv, buff));
	return (ft_suc(serv, buff));
}

int		ft_suc(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}
