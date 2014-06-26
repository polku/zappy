/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/26 13:02:33 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/26 13:08:20 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_ppo(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}

int		ft_plv(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}

int		ft_pin(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}

int		ft_sst(t_server *serv, char *buff)
{
	(void)buff;
	ft_send(serv, serv->sock_graph, "suc\n");
	return (0);
}
