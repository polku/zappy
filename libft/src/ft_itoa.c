/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 15:20:32 by jmaurice          #+#    #+#             */
/*   Updated: 2014/05/14 18:39:21 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	get_length(int n, int negative)
{
	int		length;

	length = (n == 0) ? 1 : 0;
	while (n != 0)
	{
		n = n / 10;
		length++;
	}
	if (negative)
		length++;
	return (length);
}

static void	loop(char *str, int *n, int *length)
{
	while ((*n) != 0)
	{
		str[(*length)] = (*n) % 10 + '0';
		(*n) = (*n) / 10;
		(*length)--;
	}
}

char		*ft_itoa(int n)
{
	char	*str;
	int		length;
	int		negative;

	if (n == -2147483648)
	{
		return (ft_strdup("-2147483648"));
	}
	negative = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	length = get_length(n, negative);
	str = (char *)malloc(sizeof(char) * (length + 1));
	if (str)
	{
		str[length] = '\0';
		length--;
		str[length] = '0';
		loop(str, &n, &length);
		str[0] = negative ? '-' : str[0];
	}
	return (str);
}
