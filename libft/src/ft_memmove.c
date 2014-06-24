/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 14:01:32 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:20:58 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*i;
	unsigned char	*j;
	unsigned char	k;
	void			*buffer;

	buffer = malloc(n);
	ft_memcpy(buffer, dest, n);
	i = (unsigned char *)buffer;
	j = (unsigned char *)src;
	k = 0;
	while (k < n)
	{
		*i = *j;
		i++;
		j++;
		k++;
	}
	ft_memcpy(dest, buffer, n);
	free(buffer);
	return (dest);
}
