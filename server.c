/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/20 10:48:00 by jmaurice          #+#    #+#             */
/*   Updated: 2014/06/26 13:08:35 by jmaurice         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

G_OPTARG;
G_OPTIND;
G_OPTERR;
G_OPTOPT;
G_OPTRESET;

int			init_socket(int port)
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

t_server	*crea_serv(void)
{
	t_server	*serv;

	serv = (t_server *)malloc(sizeof(t_server));
	serv->plyr = NULL;
	serv->tm.tv_sec = TIMEOUT;
	serv->tm.tv_usec = 0;
	return (serv);
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
					srv->teams = ft_add_team(srv, srv->teams, av[optind++]);
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

int			check_serv(t_server *srv)
{
	int		i;

	srv->map = (t_case **)malloc(sizeof(t_case *) * srv->map_hgt);
	i = 0;
	while (i < srv->map_hgt)
		srv->map[i++] = (t_case *)malloc(sizeof(t_case) * srv->map_width);
	srv->sock = init_socket(srv->port);
	srv->sock_graph = init_socket(srv->port + 1);
	srv->fd_max = srv->sock;
	return (0);
}

int			main(int ac, char **av)
{
	t_server	*serv;
	int			ret;

	if (ac < 2)
		return (ft_usage());
	serv = crea_serv();
	parse_opt(serv, ac, av);
	check_serv(serv);
	while (1)
	{
		ft_fdset(serv);
		ret = select(serv->fd_max + 1, &serv->rd_set, NULL, NULL, &serv->tm);
		if (FD_ISSET(serv->sock, &serv->rd_set))
			ft_add_plyr(serv);
		if (FD_ISSET(serv->sock_conn_graph, &serv->rd_set))
			ft_conn_graph(serv);
		if (FD_ISSET(serv->sock_conn_graph, &serv->rd_set))
			ft_graph(serv, serv->buff_rd);
		ft_loop(serv);
	}
	return (0);
}
