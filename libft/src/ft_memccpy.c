/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 09:49:23 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:19:45 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *s1, void *s2, int c, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	unsigned char	k;

	i = (unsigned char *)s1;
	j = (unsigned char *)s2;
	k = 0;
	while (k < n)
	{
		*i = *j;
		if (*i == (unsigned char)c)
			return (i + 1);
		i++;
		j++;
		k++;
	}
	return (NULL);
}
