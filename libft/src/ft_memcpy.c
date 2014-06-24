/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 13:42:40 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:20:44 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	unsigned char	k;

	i = (unsigned char *)dest;
	j = (unsigned char *)src;
	k = 0;
	while (k < n)
	{
		*i = *j;
		i++;
		j++;
		k++;
	}
	return (dest);
}
