/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/18 11:21:04 by jmaurice          #+#    #+#             */
/*   Updated: 2014/04/20 13:59:45 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

int		ft_printf(const char *str, ...);
void	call_int(va_list *args);
void	call_char(va_list *args);
void	call_str(va_list *args);
void	call_double(va_list *args);
void	call_ptr(va_list *args);

#endif
