/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:00:38 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 11:51:06 by nguiard          ###   ########.fr       */
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
/*	Nombre de builtin qu'on a												*/
# define BUILTIN_NB	8

/*	Pointer sur fonction de type "void(char **)", aka nos builtins			*/
typedef void (*builtin_fnc)(char **);


/* Built-in */

void	echo(char **args);
void	cd(char **args);
void	pwd(char **args);
void	clear(char **args);
void	ft_exit_builtin(char **args);
void	env(char **args);
void	export(char **args);
void	unset(char **args);
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