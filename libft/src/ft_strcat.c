/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/19 12:27:15 by jmaurice          #+#    #+#             */
/*   Updated: 2013/11/27 10:53:13 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (s2[j] != '\0')
		s1[i++] = s2[j++];
	s1[i] = '\0';
	return (s1);
}
