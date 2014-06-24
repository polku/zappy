/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 12:04:25 by jmaurice          #+#    #+#             */
/*   Updated: 2013/11/25 12:32:09 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;
	size_t	i;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (size < dlen)
		return (size + ft_strlen(src));
	i = dlen;
	dst += dlen;
	while (i < size - 1)
	{
		*dst++ = *src++;
		i++;
	}
	*dst = '\0';
	return (dlen + slen);
}
