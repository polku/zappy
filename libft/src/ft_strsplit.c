/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/21 14:55:45 by jmaurice          #+#    #+#             */
/*   Updated: 2014/03/26 11:27:03 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int		count_words(char const *s, char c)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			res++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (res);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		nb_wds;
	int		i;
	int		j;
	int		start;

	nb_wds = count_words(s, c);
	res = (char **)malloc(sizeof(char *) * nb_wds + 1);
	i = 0;
	j = 0;
	while (j < nb_wds)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		res[j++] = ft_strsub(s, start, i - start);
	}
	res[j] = NULL;
	return (res);
}
