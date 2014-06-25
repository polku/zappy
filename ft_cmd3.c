/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 11:02:21 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/25 11:02:48 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_fork(t_server *serv, t_plyr *p, char *arg)
{
	t_team	*tm;

	(void)arg;
	tm = ft_team_by_name(serv->teams, p->team_name);
	tm->nb_disp++;
	ft_send(serv, p->sock, "ok\n");
	return (0);
}

int		ft_nb_conn(t_server *serv, t_plyr *p, char *arg)
{
	t_team	*team;
	char	res[ARG_SZ];

	team = ft_team_by_name(serv->teams, arg);
	ft_strcpy(res, ft_itoa(team->nb_disp));
	ft_strcat(res, "\n");
	ft_send(serv, p->sock, res);
	return (0);
}

int		ft_unknown(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	ft_send(serv, p->sock, "ko\n");
	return (0);
}
