/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:36:33 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:18:24 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*i;
	unsigned char	*end;

	i = (unsigned char *)s;
	end = i + n;
	while (i < end)
	{
		*i = 0;
		i++;
	}
}
