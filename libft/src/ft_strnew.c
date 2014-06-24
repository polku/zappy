/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:02:44 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:26:24 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(size);
	if (ptr)
	{
		while (i <= (int)size)
		{
			ptr[i] = '\0';
			i++;
		}
		return (ptr);
	}
	else
		return (NULL);
}
