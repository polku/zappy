/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 12:11:17 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/25 11:08:40 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_error(char *str)
{
	ft_putendl(str);
	exit(1);
}

int		ft_usage(void)
{
	ft_putstr("Usage: ./serveur -p <port> -x <width> -y <height>");
	ft_putstr(" -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	return (-1);
}
