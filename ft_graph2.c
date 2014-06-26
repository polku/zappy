/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 12:53:20 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/26 13:08:11 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_msz(t_server *serv, char *buff)
{
	char	tmp[BUFF_SZ];

	(void)buff;
	sprintf(tmp, "msz %d %d\n", serv->map_width, serv->map_hgt);
	ft_send(serv, serv->sock_graph, tmp);
	return (0);
}

int		ft_bct(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}

int		ft_mct(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}

int		ft_tna(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}

int		ft_sgt(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}
