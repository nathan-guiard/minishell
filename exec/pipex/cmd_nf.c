/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:04:36 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/14 18:09:02 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_nf(char *cmd)
{
	ft_putstr_fd("command not found : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", STDERR_FILENO);
	set_ret_value(127);
	exit(127);
}

int	check_fd(t_exec *ex, t_parstab tab, int i)
{
	t_lexer	*buff;
	char	*cmd;

	buff = tab[i];
	cmd = api_command_name(buff);
	if ((buff->symbol == red_out || buff->symbol == append) && cmd == NULL)
		return (1);
	else if (ex->fd_in == -1)
	{
		ft_putstr_fd(api_last_red_in(tab[i]), 2);
		ft_putstr_fd(" : no such file or directory\n", 2);
		return (1);
	}
	else if (ex->fd_in > STDIN_FILENO)
	{
		if (cmd == NULL)
			return (1);
	}
	if (ex->fd_out == -1)
	{
		ft_putstr_fd("Error : open return -1\n", 2);
		return (1);
	}
	return (0);
}

int	heredoc_err(char *delimiter, char *line, int i)
{
	if (!line)
	{
		ft_putstr_fd("warning: here-document at line ", STDERR_FILENO);
		ft_putnbr_fd(i, STDERR_FILENO);
		ft_putstr_fd(HERDOC_ERR1, STDERR_FILENO);
		ft_putstr_fd(delimiter, 2);
		ft_putstr_fd("')\n", 2);
		return (TRUE);
	}
	if (ft_strcmp(line, delimiter) == 0)
	{
		if (i == 1)
			free(line);
		return (TRUE);
	}
	return (FALSE);
}
