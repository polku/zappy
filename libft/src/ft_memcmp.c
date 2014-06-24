/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:18:33 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:20:26 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(void *s1, void *s2, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	unsigned char	*end;

	i = (unsigned char *)s1;
	j = (unsigned char *)s2;
	end = i + n;
	while (i < end)
	{
		if (*i != *j)
			return (*i - *j);
		i++;
		j++;
	}
	return (0);
}
