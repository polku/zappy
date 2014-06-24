/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:46:32 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:24:38 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	length;
	size_t	i;

	length = ft_strlen(s) + 1;
	i = 0;
	while (i < length)
	{
		if (s[i] == c)
			return (char *)(s + i);
		i++;
	}
	return (NULL);
}
