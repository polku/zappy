/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/25 17:46:02 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:19:04 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*former;

	former = NULL;
	while (lst)
	{
		new = (t_list *)malloc(sizeof(t_list));
		new = (*f)(lst);
		if (former)
			former->next = new;
		former = new;
		lst = lst->next;
	}
	new->next = NULL;
	return (new);
}
