#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpylypen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/13 18:46:56 by dpylypen          #+#    #+#              #
#    Updated: 2017/05/11 17:01:38 by dpylypen         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = wolf3d

CC = gcc

CFLAGS = -Wall -Wextra -Werror

INCLUDES = includes/

SRCS =	srcs/main.c\
	srcs/init_wolf.c\
	srcs/start_win.c\
	srcs/keyboard.c\
	srcs/mouse.c\
	srcs/engine.c\
	srcs/color.c\
	srcs/ver_line.c\
	srcs/timing_fps.c\

HEADERS = includes/\

OBJ = $(SRCS:.c=.o)

LIBFTDIR = libft/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFTDIR)libft.a
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) -L./$(LIBFTDIR) -lft -lmlx -framework OpenGL -framework AppKit 

%.o: srcs/filereader/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%.o: srcs/tetriminos/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

%.o: srcs/%.c $(INCLUDES)
	$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDES) -I $(LIBFTDIR)

$(LIBFTDIR)libft.a: libft/Makefile
	make -C libft/

clean:
	rm -f $(OBJ)
	make clean -C $(LIBFTDIR) 

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR) 

re:  fclean all
	make re -C $(LIBFTDIR)

norm:
	norminette $(HEADERS)
	norminette $(SRCS)
	make norm -C $(LIBFTDIR)

rmsh:
	find . -name ".DS*" -o -name "._.*" -o -name "#*" -o -name "*~" -o -name "*.out" > rmsh
	xargs rm < rmsh
	rm rmsh