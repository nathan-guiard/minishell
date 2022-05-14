/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:04:36 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/14 14:25:16 by nguiard          ###   ########.fr       */
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
	if (buff->symbol == red_out || buff->symbol == append)
		return (1);
	else if (ex->fd_in == -1)
	{
		ft_putstr_fd("le fichier n'existe pas\n", 2);
		return (1);
	}
	else if (ex->fd_in > STDIN_FILENO)
	{
		if (cmd == NULL)
			return (1);
	}
	if (ex->fd_out == -1)
	{
		ft_putstr_fd("Erreur d'open\n", 2);
		return (1);
	}
	return (0);
}

int	heredoc_err(char *delimiter, char *line, int i)
{
	if (!line)
	{
		ft_putstr_fd("'warning: here-document at line ", STDERR_FILENO);
		ft_putnbr_fd(i, STDERR_FILENO);
		ft_putstr_fd(HERDOC_ERR, STDERR_FILENO);
		return (TRUE);
	}
	if (ft_strncmp(line, delimiter, ft_strlen(delimiter)) == 0)
		return (TRUE);
	return (FALSE);
}
