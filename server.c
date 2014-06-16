/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 10:48:00 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/16 15:55:12 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

extern char		*optarg;
extern int		optind;
extern int		opterr;
extern int		optopt;
extern int		optreset;

int			init_conn(int port)
{
	int					sock;
	struct sockaddr_in	sai;
	struct protoent		*prot;

	prot = getprotobyname("tcp");
	if ((sock = socket(PF_INET, SOCK_STREAM, prot->p_proto)) == -1)
		ft_error("\x1b[31mError socket\x1b[0m");
	sai.sin_family = PF_INET;
	sai.sin_port = htons(port);
	sai.sin_addr.s_addr = INADDR_ANY;
	if (bind(sock, (struct sockaddr *)&sai, sizeof(sai)) == -1)
	{
		ft_error("\x1b[31mError bind\x1b[0m");
		return (-1);
	}
	if (listen(sock, NB_CONN) == -1)
		ft_error("\x1b[31mError listen\x1b[0m");
	return (sock);
}

t_server	*init_serv()
{
	t_server	*serv;

	serv = (t_server *)malloc(sizeof(t_server));
	serv->plyr = NULL;
	serv->tm.tv_sec = TIMEOUT;
	serv->tm.tv_usec = 0;
	return (serv);
}

int			add_plyr(t_server *serv)
{
	int					sz;
	struct sockaddr_in	sai;
	int					sock;
	static int			id = 0;

	sz = sizeof(sai);
	sock = accept(serv->sock, (struct sockaddr *)&sai, (socklen_t *)&sz);
	if (sock == -1)
		ft_error("Error connection");
	ft_send(serv, sock, "BIENVENUE\n");
	serv->fd_max = (sock > serv->fd_max ? sock : serv->fd_max);
	ft_putendl("Connection etablished");
	serv->plyr = ft_add_plist(sock, id, serv->plyr); // + nom team
	id++;
	// recup nom equipe, chk nb _conn, auth ou pas conn , send dim md
	return (0);
}

int			del_plyr(t_server *serv, t_plyr *p)
{
	close(p->sock);
	serv->plyr = ft_del_plist(serv->plyr, p);
	return (0);
}

int			ft_usage(void)
{
	ft_putstr("Usage: ./serveur -p <port> -x <width> -y <height>");
	ft_putstr(" -n <team> [<team>] [<team>] ... -c <nb> -t <t>\n");
	return (-1);
}

int			parse_opt(t_server *srv, int ac, char **av)
{
	while (getopt(ac, av, "p:x:y:n:c:t:") != -1)
	{
		if (optopt != '?' && optarg[0] != '-')
		{
			if (optopt == 'p')
				srv->port = ft_atoi(optarg);
			if (optopt == 'x')
				srv->map_width = ft_atoi(optarg);
			if (optopt == 'y')
				srv->map_hgt = ft_atoi(optarg);
			if (optopt == 'n')
			{
				optind--;
				while (av[optind][0] != '-')
					ft_printf("team = %s\n", av[optind++]);
//					add_team(av[optind++]);
			}
			if (optopt == 'c')
				srv->max_plyr = ft_atoi(optarg);
			if (optopt == 't')
				srv->speed = ft_atoi(optarg);
		}
		else
			return (ft_usage());
	}
	return (0);
}

int		check_srv(t_server *srv)
{
	int		i;

	// verif ts args corrects
	// init ressources
	srv->map = (t_case **) malloc(sizeof(t_case *) * srv->map_hgt);
	i = 0;
	while (i < srv->map_hgt)
		srv->map[i++] = (t_case *) malloc(sizeof(t_case) * srv->map_width);
	srv->sock = init_conn(srv->port);
	srv->sock_graph = init_conn(srv->port + 1);
	srv->fd_max = srv->sock;
	return (0);
}

void		tostring(t_server *srv)
{
	ft_printf("sock = %d\nport = %d\nx = %d\ny = %d\nc = %d\nt = %d\n",
			  srv->sock, srv->port, srv->map_width, srv->map_hgt, srv->max_plyr, srv->speed);
}

int			main(int ac, char **av)
{
	t_server	*srv;
	int			ret;

	if (ac < 2)
		return (ft_usage());
	srv = init_serv();
	parse_opt(srv, ac, av);
	check_srv(srv);
	while (1)
	{
		ft_fdset(srv);
		ret = select(srv->fd_max + 1, &srv->rd_set, NULL, NULL, &srv->tm);
		if (FD_ISSET(srv->sock, &srv->rd_set))
			add_plyr(srv);
		ft_fdisset(srv);
//		if (ret == 0)
//			ft_putendl("timeout");
	}
	return (0);
}
