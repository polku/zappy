/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/20 15:01:03 by jmaurice          #+#    #+#             */
/*   Updated: 2013/12/04 10:38:07 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*s2;

	i = 0;
	s2 = malloc(sizeof(ft_strlen(s) + 1));
	if (s2)
	{
		while (s[i] != '\0')
		{
			s2[i] = (*f)(i, s[i]);
			i++;
		}
		s2[i] = '\0';
		return (s2);
	}
	else
		return (NULL);
}
