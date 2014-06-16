/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/06/09 13:52:44 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/16 16:21:31 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <sys/time.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <sys/select.h>
# include <netdb.h>
# include <netinet/in.h>
# include <stdlib.h>
# include <fcntl.h>
# include <dirent.h>
# include <unistd.h>
# include <stdio.h>

# include "libft.h"
# include "ft_printf.h"

# define MAX_CONN		256
# define BUFF_SZ		512
# define NB_CONN		10
# define NAME			256
# define TIMEOUT		0
# define FOOD			0
# define LINEMATE		1
# define DERAUMERE		2
# define SIBUR			3
# define MENDIANE		4
# define PHIRAS			5
# define THYSTAME		6
# define NB_ELEM		7

typedef enum			e_dir
{
	N = 1,
	E = 2,
	S = 3,
	W = 4
}						t_dir;

typedef struct			s_timer
{
	time_t				start;
	time_t				end;
	char				msg[BUFF_SZ];
}						t_timer;

typedef struct			s_plyr
{
	int					id;
    int					sock;
	char				team_name[NAME];
	int					pv;
	int					lvl;
	int					inv[NB_ELEM];
	int					x;
	int					y;
	t_dir				dir;
    struct s_plyr		*next;
}						t_plyr;

typedef struct			s_egg
{
	int					x;
	int					y;
	char				team_name[NAME];
	struct s_egg		*next;
}						t_egg;

typedef struct			s_team
{
    char				name[NAME];
	int					nb_disp;
	t_egg				*egg;
    struct s_team		*next;
}						t_team;

typedef struct			s_case
{
	int					elem[NB_ELEM];
	t_plyr				*plyr;
}						t_case;

typedef struct          s_server
{
    int                 sock;
	int					sock_graph;
	int					port;
    struct timeval      tm;
    t_plyr            	*plyr;
	t_team				*teams;
    fd_set              rd_set;
    int                 fd_max;
	int					map_width;
	int					map_hgt;
	t_case				**map;
	int					max_plyr;
	int					speed;
	char				buff_rd[BUFF_SZ];
}						t_server;

void	ft_error(char *str);
t_plyr  *ft_add_plist(int sock, int id, t_plyr *lst);
t_plyr  *ft_del_plist(t_plyr *lst, t_plyr *elem);
int		ft_recv(t_server *serv, t_plyr *p);
int		ft_fdset(t_server *serv);
int		ft_fdisset(t_server *serv);
int		ft_cmd(t_server *serv, t_plyr *p, char *buff);
int		ft_avance(t_server *serv, t_plyr *p, char *buff);
int		ft_droite(t_server *serv, t_plyr *p, char *buff);
int		ft_gauche(t_server *serv, t_plyr *p, char *buff);
int		ft_voir(t_server *serv, t_plyr *p, char *buff);
int		ft_inv(t_server *serv, t_plyr *p, char *buff);
int		ft_take(t_server *serv, t_plyr *p, char *buff);
int		ft_put(t_server *serv, t_plyr *p, char *buff);
int		ft_exp(t_server *serv, t_plyr *p, char *buff);
int		ft_broadcast(t_server *serv, t_plyr *p, char *buff);
int		ft_incantation(t_server *serv, t_plyr *p, char *buff);
int		ft_fork(t_server *serv, t_plyr *p, char *buff);
int		ft_nb_conn(t_server *serv, t_plyr *p, char *buff);
int		ft_unknown(t_server *serv, t_plyr *p, char *buff);
int		ft_send(t_server *serv, int dest, char *msg);
int		ft_send_all(t_server *serv, char *msg);

#endif
