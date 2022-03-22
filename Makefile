# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/03/22 13:09:50 by nguiard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/main.c								\
		srcs/prompt.c							\
		srcs/utils.c							\
		srcs/signals.c							\
		builtin/echo.c							\
		builtin/cd.c							\
		builtin/pwd.c							\
		builtin/exit.c							\
		builtin/clear.c							\
		builtin/env.c							\
		builtin/export.c						\
		builtin/unset.c							\
		parsing/remove_command_name.c			\
		parsing/get_builtin_fnc.c				\
		parsing/is_a_builtin.c					\
		parsing/exec_path.c						\
		parsing/variables/variable_replace.c	\
		parsing/variables/variable_utils.c		\
		parsing/lexer/symbol_table.c			\
		parsing/lexer/utils.c					\
		parsing/lexer/get_symbol.c				\
		parsing/lexer/full_symbol_table.c		\
		parsing/lexer/replace_special_char.c	\
		parsing/lexer/quote_handling.c			\
		parsing/lexer/split_the_unsplitted.c	\
		list/ft_lexeradd_back.c					\
		list/ft_lexeradd_front.c				\
		list/ft_lexerclear.c					\
		list/ft_lexerdelone.c					\
		list/ft_lexerindex.c					\
		list/ft_lexerlast.c						\
		list/ft_lexernew.c						\
		list/ft_lexersize.c						\
		list/ft_lexerinsert.c					\
		exec/builtin.c							\
		exec/exec_simple_command.c				\
		
SHELL := /bin/zsh

CFLAGS = -g -lreadline -fsanitize=address -Wall -Werror -Wextra

CFLAGS_OBJ = -g -fsanitize=address -Wall -Werror -Wextra

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
	@${CC} ${INCLUDE} ${CFLAGS_OBJ} -c $< -o ${<:.c=.o} 2>>error.log
	$(eval n=$(shell echo $$(($(nb)/15 * 35))))
	$(eval a=$(shell echo $$((202 - $(n)))))
	@if [ ${nb} = "1" ]; then\
		printf "\033[1;0f\033[?25l~~~~~~~~~~TURBO MAKEFILE~~~~~~~~~~\033[J";\
	fi 2> error.log
	@printf "\033[0;38;5;%dm" "${a}"
	@echo -n "\033[2;0fCompilation de l'objet" ${nb} "terminee\033[0m\n"
	$(eval nb=$(shell echo $$(($(nb)+1))))

${NAME}: rm_log ${OBJ}
	@make -C libft
	@${CC} ${INCLUDE} ${OBJ} ${LIBFT} ${CFLAGS} -o ${NAME} 2>>error.log
	@echo "\033[1;92m\033[6;0fminishell pret!\033[0m\033[?25h"
	@cat error.log 2>/dev/null

clean:
	@rm -f ${OBJ}
	@echo "clean ok!"

fclean:
	@rm -f ${OBJ} ${NAME}
	@echo "fclean ok!"

re: fclean all

error:
	@printf "\033[0;0H\033[1;31m\033[JAn error as occured:\033[J\033[0m\n"
	@cat error.log 2>/dev/null
	@echo "\033[?25h"

rm_log:
	@rm -rf error.log

.PHONY: all clean fclean re error rm_log
