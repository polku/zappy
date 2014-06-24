/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:04:15 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:20:02 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*i;
	unsigned char	*end;

	i = (unsigned char *)s;
	end = i + n;
	while (i < end)
	{
		if (*i == (unsigned char)c)
			return (i);
		i++;
	}
	return (NULL);
}
