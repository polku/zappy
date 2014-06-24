/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:16:34 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:25:32 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s)
{
	int		i;
	char	*cpy;

	i = 0;
	cpy = (char *)malloc(sizeof(s));
	if (!cpy)
		return (NULL);
	else
	{
		while (s[i] != 0)
		{
			cpy[i] = s[i];
			i++;
		}
	}
	cpy[i] = '\0';
	return (cpy);
}
