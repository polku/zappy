/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/13 11:38:58 by jmaurice          #+#    #+#             */
/*   Updated: 2013/12/30 19:20:17 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *l)
{
	t_list	*tmp;
	int		nb;

	tmp = l;
	nb = 0;
	while (tmp != NULL)
	{
		nb++;
		tmp = tmp->next;
	}
	return (nb);
}
