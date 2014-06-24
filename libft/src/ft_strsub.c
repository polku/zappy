/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:13:06 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:40:21 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*cpy;

	cpy = ft_strnew(len);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (cpy)
	{
		ft_strncpy(cpy, s + start, len);
		cpy[len] = '\0';
		return (cpy);
	}
	else
		return (NULL);
}
