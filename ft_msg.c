/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/21 10:47:24 by jmaurice          #+#    #+#             */
/*   Updated: 2014/05/25 12:19:40 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_irc.h"

int			unicast(t_server *serv, t_client *exp, int dest, char *msg)
{
	char	buff[BUFF_SZ];
	int		chk;

	(void)serv;
	if (exp)
		ft_strcpy(buff, exp->nick);
	else
		ft_strcpy(buff, "SERVER");
	ft_strcat(buff, " sent you > ");
	ft_strcat(buff, msg);
	ft_strcat(buff, "\n");
	chk = send(dest, buff, ft_strlen(buff), 0);
	return (0);
}

int			broadcast(t_server *serv, t_client *exp, char *msg, int chan)
{
	t_client	*tmp;
	char		buff[1024];
	int			chk;

	chk = 0;
	ft_bzero(buff, BUFF_SZ);
	if (exp)
		ft_strcpy(buff, exp->nick);
	else
		ft_strcpy(buff, "SERVER");
	ft_strcat(buff, " > ");
	ft_strcat(buff, msg);
	ft_strcat(buff, "\n");
	tmp = serv->cli;
	while (tmp)
	{
		if (tmp->chan == chan && chan != -1)
			chk = send(tmp->sock, buff, ft_strlen(buff), 0);
		tmp = tmp->next;
	}
	return (chk);
}
