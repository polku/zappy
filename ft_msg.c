/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 10:47:24 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/16 14:45:00 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int			ft_send(t_server *serv, int dest, char *msg)
{
	int		chk;

	(void)serv;
	chk = send(dest, msg, ft_strlen(msg), 0);
	return (0);
}

int			ft_send_all(t_server *serv, char *msg)
{
	t_plyr		*tmp;
	int			chk;

	chk = 0;
	tmp = serv->plyr;
	while (tmp)
	{
		chk = send(tmp->sock, msg, ft_strlen(msg), 0);
		tmp = tmp->next;
	}
	return (chk);
}
