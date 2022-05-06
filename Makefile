# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/16 15:42:20 by nguiard           #+#    #+#              #
#    Updated: 2022/05/05 19:05:41 by tgeorgin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC =	srcs/main.c										\
		srcs/prompt.c									\
		srcs/utils.c									\
		srcs/signals.c									\
		builtin/echo.c									\
		builtin/cd.c									\
		builtin/pwd.c									\
		builtin/exit.c									\
		builtin/clear.c									\
		builtin/env.c									\
		builtin/export.c								\
		builtin/unset.c									\
		parsing/remove_command_name.c					\
		parsing/get_builtin_fnc.c						\
		parsing/is_a_builtin.c							\
		parsing/exec_path.c								\
		parsing/variables/variable_replace.c			\
		parsing/variables/variable_utils.c				\
		parsing/lexer/utils.c							\
		parsing/lexer/get_symbol.c						\
		parsing/lexer/full_symbol_table.c				\
		parsing/lexer/replace_special_char.c			\
		parsing/lexer/quote_handling.c					\
		parsing/lexer/split_the_unsplitted.c			\
		parsing/lexer/split_the_pipes.c					\
		parsing/lexer/rename_strings.c					\
		parsing/lexer/remaining_strings_are_arguments.c	\
		parsing/lexer/replace_quotes.c					\
		parsing/lexer/replace_dollar.c					\
		parsing/env/ft_getenv.c							\
		parsing/env/turn_env_into_list.c				\
		parsing/env/get_env_node.c						\
		parsing/env/turn_env_into_tab.c					\
		parsing/env/set_ret_value.c						\
		parsing/errors/check_error_full_string.c		\
		parsing/parsing_main.c							\
		parsing_api/api_last_red_out.c					\
		parsing_api/api_last_red_in.c					\
		parsing_api/api_get_command_tab.c				\
		parsing_api/api_every_red_in.c					\
		parsing_api/api_every_red_out.c					\
		parsing_api/api_heredoc_delimiter.c				\
		parsing_api/api_full_command.c					\
		parsing_api/api_command_name.c					\
		list/ft_lexeradd_back.c							\
		list/ft_lexeradd_front.c						\
		list/ft_lexerclear.c							\
		list/ft_lexerdelone.c							\
		list/ft_lexerindex.c							\
		list/ft_lexerlast.c								\
		list/ft_lexernew.c								\
		list/ft_lexersize.c								\
		list/ft_lexerinsert.c							\
		list/ft_lexerpop.c								\
		list/ft_lexerprint.c							\
		exec/builtin.c									\
		exec/exec_simple_command.c						\
		exec/pipex/pipex.c								\
		exec/pipex/utils_pipex.c						\
		exec/pipex/exec_builtins.c						\
		
SHELL := /bin/zsh

ADD_FLAGS = -g #-fsanitize=address

CFLAGS = -lreadline -Wall -Werror -Wextra ${ADD_FLAGS}

CFLAGS_OBJ =  -Wall -Werror -Wextra ${ADD_FLAGS}

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

${NAME}: ${OBJ}
	@make -s -C libft
	@${CC} ${INCLUDE} ${OBJ} ${LIBFT} ${CFLAGS} -o ${NAME} 2>>error.log
	@echo "\033[1;92m\033[6;0fminishell pret!\033[0m\033[?25h"
	@cat error.log 2>/dev/null

all: ${NAME}

clean:
	@rm -f ${OBJ}
	@echo "clean ok!"

fclean:
	@rm -f ${OBJ} ${NAME}
	@echo "fclean ok!"

ultraclean:
	@rm -rf ${OBJ} ${NAME}
	@make fclean -C libft 1>/dev/null
	@echo "ultraclean ok!"

re: fclean all

error:
	@printf "\033[0;0H\033[1;31m\033[JAn error has occured:\033[J\033[0m\n"
	@cat error.log 2>/dev/null
	@echo "\033[?25h"

rm_log:
	@rm -rf error.log

.PHONY: all clean fclean re error rm_log
