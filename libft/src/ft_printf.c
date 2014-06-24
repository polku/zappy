/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/17 12:36:40 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:38:47 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void		(*g_tab[4]) (va_list *) =
{
	call_int, call_char, call_str, call_double
};

static int	is_flag(const char *str, int *i)
{
	if (str[*i] == '%' && (ft_strchr("diD", str[*i + 1]) != 0))
		return (0);
	if (str[*i] == '%' && (ft_strchr("cC", str[*i + 1]) != 0))
		return (1);
	if (str[*i] == '%' && (ft_strchr("s", str[*i + 1]) != 0))
		return (2);
	if (str[*i] == '%' && (ft_strchr("efgEFG", str[*i + 1]) != 0))
		return (3);
	if (str[*i] == '%' && str[*i + 1] == '%')
		*i += 1;
	return (-1);
}

int			ft_printf(const char *str, ...)
{
	va_list		args;
	int			res;
	int			i;

	va_start(args, str);
	i = 0;
	while (str[i])
	{
		res = is_flag(str, &i);
		if (res != -1)
		{
			(*g_tab[res]) (&args);
			i++;
		}
		else
			ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (0);
}
