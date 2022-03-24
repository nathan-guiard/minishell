/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:00:38 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 12:20:49 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "lexer.h"
# include "parsing_api.h"
# include "variables.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>

# define TRUE 		1
# define FALSE 		-42
# define ERR		-420
# define M_ERR		-90
# define P_ERR		-54
/*	Strings a strcmp avec le resultat si jamais on a des erreurs			*/
# define S_ERR		"\033error string"
# define S_MERR		"\033malloc error string"
# define S_PERR		"\033parsing error string"
/* TRES MAUVAIS MDR															*/
# define DS_MERR	(char **)&S_MERR
# define ALONE		4103
/*	Nombre de builtin qu'on a												*/
# define BUILTIN_NB	8
/*	Pointer sur fonction de type "void(char **)", aka nos builtins			*/
typedef void (*builtin_fnc)(char **);
typedef	char **t_doubletab;

extern t_list	*g_env;

/*	Built-in	*/

void	echo(char **args);
void	cd(char **args);
void	pwd(char **args);
void	clear(char **args);
void	ft_exit_builtin(char **args);
void	ft_env(char **args);
void	export(char **args);
void	unset(char **args);
void	ft_exit(int exit_value, char **args);

/*	Utils	*/

void	free_tabtab(char **tab);
void	catch_signals(void);
char	*prompt(void);
char	*get_prompt_text(void);

/*	Exec	*/
int		builtin(char **command);
int		exec_simple_command(char **command, char **env);

/*	Parsing	*/

t_parstab full_parsing(char *line);

char	**remove_command_name(char **);
int		is_a_builtin(char *cmd_name);
char 	**get_builtin_tab_name(void);
void 	*get_builtin_fnc(char *cmd_name);
char 	*exec_path(char *cmd_name);
char 	*replace_variables(char *line);
t_symbol	get_symbol(char *content);
char	*translate_symbol(t_symbol symbol);
t_parstab	rename_strings(t_parstab tab);

t_list *test(char *line);
void	free_parstab(t_parstab tab);

#endif