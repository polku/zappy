/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 13:01:05 by jmaurice          #+#    #+#             */
/*   Updated: 2013/12/12 16:03:15 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;
	int		i;

	length = ft_strlen(s);
	i = length;
	while (i >= 0)
	{
		if (s[i] == c)
			return (char *)(s + i);
		i--;
	}
	return (NULL);
}
