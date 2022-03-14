# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/03/14 13:23:53 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =  srcs/main.c						\
		srcs/prompt.c					\
		srcs/utils.c					\
		srcs/signals.c					\
		builtin/echo.c					\
		builtin/cd.c					\
		builtin/pwd.c					\
		builtin/exit.c					\
		builtin/clear.c					\
		builtin/env.c					\
		builtin/export.c				\
		builtin/unset.c					\
		parsing/remove_command_name.c	\
		parsing/get_builtin_fnc.c		\
		parsing/is_a_builtin.c			\
		parsing/exec_path.c				\
		parsing/variables.c				\
		exec/builtin.c					\
		exec/exec_simple_command.c		\
		

CFLAGS = -g -lreadline #-fsanitize=address #-Wall -Werror -Wextra

CFLAGS_OBJ = -g #-fsanitize=address #-Wall -Werror -Wextra

OBJ = ${SRC:.c=.o}

LIBFT = libft/libft.a

NAME = minishell

CC = gcc

INCLUDE = -Iinclude/

all: ${NAME}

nb:=1

n:=0

a:=0

.c.o:
	@${CC} ${INCLUDE} ${CFLAGS_OBJ} -c $< -o ${<:.c=.o}
#	$(eval n=$(shell echo $$(($(nb)/5 * 70))))
#	$(eval a=$(shell echo $$((202 - $(n)))))
#	@printf "\033[?25l\033[0;0f"
#	@printf "\033[1;0f~~~~~~~~~~TURBO MAKEFILE~~~~~~~~~~\033[J"
#	@printf "\033[0;38;5;%dm" "${a}"
#	@echo -n "\033[2;0fCompilation de l'objet" ${nb} "terminee\033[J\033[0m\n"
#	$(eval nb=$(shell echo $$(($(nb)+1))))

${NAME}: ${OBJ}
	@make -C libft
	@${CC} ${INCLUDE} ${OBJ} ${LIBFT} ${CFLAGS} -o ${NAME}
#	@echo "\033[1;92m\033[6;0fminishell pret!\033[0m\033[?25h"

clean:
	@rm -f ${OBJ}
	@echo "clean ok!"

fclean:
	@rm -f ${OBJ} ${NAME}
	@echo "fclean ok!"

re: fclean all

.PHONY: all clean fclean re
