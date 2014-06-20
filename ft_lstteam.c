/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstteam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/20 14:25:04 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/20 14:49:43 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

t_team	*ft_team_by_name(t_team *lst, char *nm)
{
	t_team	*tmp;

	tmp = lst;
	while (tmp)
	{
		if (ft_strcmp(tmp->name, nm) == 0)
			return (tmp);
	}
	return (NULL);
}

t_team	*ft_add_team(t_server *serv, t_team *lst, char *nm)
{
	t_team	*new;

	new = (t_team *)malloc(sizeof(t_team));
	ft_strcpy(new->name, nm);
	new->nb_disp = serv->max_plyr;
	new->nb_lvl_max = 0;
	new->egg = NULL;
	new->next = lst;
	return (new);
}
