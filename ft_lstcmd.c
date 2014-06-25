/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 13:15:35 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/25 11:06:44 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_cmd	*ft_add_cmd(t_cmd *lst, char *cmd, char *arg)
{
	t_cmd			*tmp;
	t_cmd			*new;
	struct timeval	time;
	static int		delay[NB_CMD] = { 7, 7, 7, 7, 1, 7, 7, 7, 7, 300, 42, 0 };

	gettimeofday(&time, NULL);
	new = (t_cmd *)malloc(sizeof(t_cmd));
	new->type = ft_cmd(cmd);
	new->end.tv_usec = time.tv_usec + delay[new->type] * SEC;
	ft_strcpy(new->arg, arg);
	new->next = NULL;
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (lst);
}

t_cmd	*ft_del_cmd(t_cmd *lst)
{
	t_cmd	*sv;

	sv = lst->next;
	free(lst);
	return (sv);
}
