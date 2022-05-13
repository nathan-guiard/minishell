/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:22:12 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/13 18:02:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static int	how_long_args(t_lexer *list)
{
	t_lexer	*buff;
	int		res;

	res = 0;
	buff = list;
	while (buff)
	{
		if (buff->symbol == argument)
			res++;
		buff = buff->next;
	}
	return (res);
}

char	**args_tab(t_parstab tab, int i)
{
	t_lexer	*ls;
	char	**args;
	int		j;
	int		len;

	len = how_long_args(tab[i]);
	ls = tab[i];
	j = 1;
	args = ft_calloc(sizeof(char *), (len + 2));
	args[0] = ft_strdup("oui");
	while (ls)
	{
		if (ls->symbol == argument)
		{
			args[j] = ft_strdup(ls->content);
			j++;
		}
		ls = ls->next;
	}
	return (args);
}

int	exec_builtin(char *cmd, t_parstab tab, int i)
{
	char	**args;

	args = args_tab(tab, i);
	if (ft_strcmp(cmd, "pwd") == 0)
		pwd(args);
	else if (ft_strcmp(cmd, "env") == 0)
		ft_env(args);
	else if (ft_strcmp(cmd, "echo") == 0)
		echo(args);
	else if (ft_strcmp(cmd, "export") == 0)
		export(args);
	else if (ft_strcmp(cmd, "cd") == 0)
		cd(args);
	else if (ft_strcmp(cmd, "unset") == 0)
		unset(args);
	else if (ft_strcmp(cmd, "exit") == 0)
		ft_exit_builtin(args);
	free_tabtab(args);
	return (TRUE);
}

int	exec_builtin_pipe(t_exec *ex, int i, t_parstab tab, int *pip)
{
	int		tmp_fd_out;
	char	**cmd;

	cmd = api_full_command(tab[i]);
	redirect(tab, ex, i, pip);
	if (ex->fd_out > STDOUT_FILENO)
	{
		tmp_fd_out = dup(STDOUT_FILENO);
		dup2(ex->fd_out, STDOUT_FILENO);
	}
	exec_builtin(cmd[0], tab, i);
	if (ex->fd_out > STDOUT_FILENO)
	{
		dup2(tmp_fd_out, STDOUT_FILENO);
		close(tmp_fd_out);
	}
	exit(0);
	return (0);
}
