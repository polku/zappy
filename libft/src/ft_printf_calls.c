/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_calls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/05 18:37:41 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 13:49:54 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

void	call_int(va_list *args)
{
	ft_putstr(ft_itoa(va_arg(*args, int)));
}

void	call_char(va_list *args)
{
	char	c;

	c = (char)va_arg(*args, int);
	if (c % 256 != 0)
		ft_putchar(c);
}

void	call_str(va_list *args)
{
	ft_putstr(va_arg(*args, char*));
}

void	call_double(va_list *args)
{
	int		tmp;
	double	db;

	db = va_arg(*args, double);
	tmp = (int)db;
	db = (double)(db - tmp);
	ft_putstr(ft_itoa(tmp));
	ft_putchar('.');
	tmp = db * 100;
	ft_putstr(ft_itoa(tmp));
}
