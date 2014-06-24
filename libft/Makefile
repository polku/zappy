#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jmaurice <jmaurice@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/20 09:44:39 by jmaurice          #+#    #+#              #
#    Updated: 2013/12/31 12:40:22 by jmaurice         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

CC = llvm-gcc
CFLAGS = -c -Wall -Wextra -Werror
INC = includes/
FILES = ft_memset ft_bzero ft_memcpy ft_memccpy ft_memmove\
		ft_memchr ft_memcmp ft_strlen ft_strdup ft_strcpy ft_strncpy\
		ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr\
		ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit\
		ft_isalnum ft_isascii ft_isprint ft_toupper ft_tolower ft_memalloc\
		ft_memdel ft_strnew ft_strdel ft_strclr ft_striter ft_striteri\
		ft_strmap ft_strmapi ft_strequ ft_strnequ ft_strsub ft_strjoin\
		ft_strtrim ft_strsplit ft_itoa ft_putchar ft_putstr ft_putendl\
		ft_putnbr ft_putchar_fd ft_putstr_fd ft_putendl_fd ft_putnbr_fd\
		ft_lstnew ft_lstdelone ft_lstdel ft_lstadd ft_lstcat ft_lstsize\
		ft_lstiter ft_lstmap ft_free_arr ft_get_next_line ft_printf_calls\
		ft_printf
SRC = $(addprefix src/, $(addsuffix .c, $(FILES)))
OBJ = $(addsuffix .o, $(FILES))
NAME = libft.a

all: $(NAME)

$(NAME): $(OBJ) $(INC)libft.h
	ar rc $@ $^
	ranlib $@

$(OBJ): $(SRC)
	$(CC) $(CFLAGS) -I$(INC) $^

.PHONY: clean

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
