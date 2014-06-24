/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/04 11:48:34 by jmaurice          #+#    #+#             */
/*   Updated: 2014/01/29 18:56:02 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static int	buff_to_line(char **line, char *buff, char *p)
{
	int	len;

	if (p)
	{
		len = ft_strlen(p);
		*p = '\0';
		ft_strncat(*line, buff, p - buff + 1);
		ft_strcpy(buff, p + 1);
		ft_memset(buff + len, 0, BUFF_SIZE - len);
		return (1);
	}
	else
	{
		ft_strcat(*line, buff);
		ft_memset(buff, 0, BUFF_SIZE);
		return (0);
	}
}

int			ft_get_next_line(int const fd, char **line)
{
	static char		buff[BUFF_SIZE] = "";
	int				chk;
	char			*p;

	chk = 1;
	ft_strclr(*line);
	while (chk)
	{
		if (buff[0] == '\0')
			chk = read(fd, buff, BUFF_SIZE);
		p = ft_strchr(buff, '\n');
		if (buff_to_line(line, buff, p))
			return (1);
	}
	return (0);
}
