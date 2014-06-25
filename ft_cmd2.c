/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/25 11:01:30 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/25 11:02:01 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int		ft_take(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	ft_send(serv, p->sock, "ko\n");
	return (0);
}

int		ft_put(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	ft_send(serv, p->sock, "ko\n");
	return (0);
}

int		ft_exp(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	ft_send(serv, p->sock, "ko\n");
	return (0);
}

int		ft_broadcast(t_server *serv, t_plyr *exp, char *arg)
{
	t_plyr	*tmp;

	tmp = serv->plyr;
	while (tmp)
	{
		if (tmp != exp)
			ft_send(serv, tmp->sock, arg);
		tmp = tmp->next;
	}
	ft_send(serv, exp->sock, "ok\n");
	return (0);
}

int		ft_incantation(t_server *serv, t_plyr *p, char *arg)
{
	(void)arg;
	ft_send(serv, p->sock, "ko\n");
	return (0);
}
