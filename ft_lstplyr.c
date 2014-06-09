/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcli.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 14:58:08 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/09 16:46:43 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_plyr	*ft_add_plist(int sock, int id, t_plyr *lst)
{
	t_plyr	*new;

	new = (t_plyr *)malloc(sizeof(t_plyr));
	if (new)
	{
		new->sock = sock;
		new->id = id;
		new->next = lst;
		return (new);
	}
	else
		return (NULL);
}

t_plyr	*ft_del_plist(t_plyr *lst, t_plyr *elem)
{
	t_plyr	*tmp;
	t_plyr	*prev;

	tmp = lst;
	if (tmp == elem)
	{
		tmp = tmp->next;
		free(elem);
		return (tmp);
	}
	if (tmp->next == NULL)
	{
		free(tmp);
		return (NULL);
	}
	while (tmp && tmp != elem)
	{
		prev = tmp;
		tmp = tmp->next;
	}
	prev->next = tmp->next;
	free(elem);
	return (lst);
}
