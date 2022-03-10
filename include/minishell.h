/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:00:38 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 10:48:31 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>

# define TRUE 		1
# define FALSE 		-42
# define ERR		420
# define BUILTIN_NB	5

/*	Pointer sur fonction de type "void(char **)", aka nos builtins			*/
typedef void (*builtin_fnc)(char **);
/*	Fonction qui retourne un pointeur sur fonction "void(char **)"			*/
typedef builtin_fnc (*ret_builtin_fnc)();

/* Built-in */

void	echo(char **args);
void	cd(char **args);
void	pwd(char **args);
void	clear(char **args);
void	ft_exit_builtin(char **args);
void	ft_exit(int exit_value, char **args);

/* Utils */

void	free_tabtab(char **tab);
void	catch_signals(void);
char	*prompt(void);
char		*get_prompt_text(void);


/* Parsing */

char	**remove_command_name(char **);
int		is_a_builtin(char *cmd_name);
char 	**get_builtin_tab_name(void);
void 	*get_builtin_fnc(char *cmd_name);
#endif