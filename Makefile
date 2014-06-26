#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:44:39 by jmaurice          #+#    #+#              #
#    Updated: 2014/06/26 13:03:49 by jmaurice         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = llvm-gcc
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -Llibft/ -lft
INC = -Ilibft/includes/ -I./
LIB = libft/libft.a
FILES_SERV = server ft_action ft_cmd ft_cmd2 ft_cmd3 ft_lstcmd ft_lstplyr\
			ft_lstteam ft_msg ft_plyr ft_utils ft_graph ft_graph2 ft_graph3
SRC_SERV = $(addsuffix .c, $(FILES_SERV))
OBJ_SERV = $(addsuffix .o, $(FILES_SERV))
SERV_PATH = ./serveur/
NAME_SERV = $(SERV_PATH)serveur

.PHONY: clean fclean re all

all: $(LIB) $(NAME_SERV) $(NAME_CLI)

$(LIB):
	make -C libft/

$(NAME_SERV): $(OBJ_SERV) $(OBJ_COMM)
	mkdir -p $(SERV_PATH)
	$(CC) -o $@ $^ $(LDFLAGS)

$(OBJ_SERV): $(SRC_SERV) $(SRC_COMM)
	$(CC) -c $(CFLAGS) $^ $(INC)

clean:
	/bin/rm -f $(OBJ_SERV)
	/bin/rm -f debug

fclean: clean
	/bin/rm -f $(NAME_SERV)

re: fclean all
