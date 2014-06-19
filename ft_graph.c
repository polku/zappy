/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_graph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/19 15:32:37 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/19 15:40:18 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

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
		return (ft_msz(serv, buff));
	if (ft_strncmp(buff, "ppo ", 4))
		return (ft_msz(serv, buff));
	if (ft_strncmp(buff, "plv ", 4))
		return (ft_msz(serv, buff));
	if (ft_strncmp(buff, "pin ", 4))
		return (ft_msz(serv, buff));
	if (ft_strncmp(buff, "sst ", 4))
		return (ft_msz(serv, buff));
	return (ft_suc(serv, buff));
}
