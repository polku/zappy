/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/12 19:37:22 by jmaurice          #+#    #+#             */
/*   Updated: 2013/12/13 17:47:01 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstcat(t_list **lst, t_list *new)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (*lst == NULL)
		*lst = new;
	else
	{
		tmp = (*lst);
		tmp2 = tmp->next;
		while (tmp2 != NULL)
		{
			tmp = tmp2;
			tmp2 = tmp->next;
		}
		tmp->next = new;
	}
	new->next = NULL;
}
