/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:00:38 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 18:33:16 by nguiard          ###   ########.fr       */
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
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define READ		0
# define WRITE		1
# define TRUE 		1
# define FALSE 		-42
# define ERR		-420
# define NONE		-142
# define ALONE		4103

/*	Nombre de builtin qu'on a												*/
# define BUILTIN_NB	7

/*	Pointer sur fonction de type "void(char **)", aka nos builtins			*/
typedef void	(*t_builtin_fnc)(char **);
typedef char	**t_doubletab;

# define MERR_STR 		"Malloc error.\n"
# define HERDOC_ERR1	" delimited by end-of-file (wanted `"

extern t_list	*g_env;

/*	Built-in	*/
void		echo(char **args);
void		cd(char **args);
void		pwd(char **args);
void		clear(char **args);
void		ft_exit_builtin(char **args);
void		ft_env(char **args);
void		export(char **args);
char		*plus_equal_export(char *str);
void		unset(char **args);
void		ft_exit(int exit_value, char **args);

/*	Utils	*/
void		free_tabtab(char **tab);
void		end_signals(void);
void		catch_signals(void);
void		restore_default_sig(void);
char		*prompt(void);
char		*get_prompt_text(void);
void		free_parstab(t_parstab tab);
void		turn_env_into_list(char **env);
void		signals_heredoc(void);
void		handle_heredoc(int signum);
void		heredoc_sig(void);
void		print_exp_err(char *str);

/*	Exec	*/
int			builtin(char **command);
int			exec_simple_command(char **command, char **env);
void		pipex(t_parstab	parsing, char **envp);
int			open_files(t_symbol sb, t_lexer *ls);
void		open_all_red_out(t_lexer *ls);
void		exec_cmd(t_parstab tab, t_exec *ex, int i, int *pip);
t_exec		init_struct_exec(t_lexer *ls, char **env);
char		*prep_path(char *cmd, char **envp);
int			exec_builtin(char *cmd, t_parstab tab, int i);
void		redirect(t_parstab tab, t_exec *ex, int i, int *pip);
int			exec_builtin_pipe(t_exec *ex, int i, t_parstab tab, int *pip);
void		cmd_nf(char *cmd);
void		exec_builtin_alone(char *cmd, t_parstab tab, int i, char **env);
int			check_fd(t_exec *ex, t_parstab tab, int i);
int			heredoc_par(t_parstab tab, int i);
int			heredoc_err(char *delimiter, char *line, int i);

/*	Parsing	*/
t_parstab	full_parsing(char *line);
char		**remove_command_name(char **command);
int			is_a_builtin(char *cmd_name);
char		**get_builtin_tab_name(void);
void		*get_builtin_fnc(char *cmd_name);
char		*exec_path(char *cmd_name);
char		*replace_variables(char *line);
t_symbol	get_symbol(char *content);
char		*translate_symbol(t_symbol symbol);
t_parstab	rename_strings(t_parstab tab);
char		*ft_getenv(char *name);
t_list		*get_env_node(char *name);
int			where_is_equal_sign(char *str);

/*	env	*/
char		**turn_env_into_tab(void);
void		set_ret_value(unsigned char i);

#endif