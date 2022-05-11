/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:04:36 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/11 20:44:59 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cmd_nf(char *cmd)
{
	ft_putstr_fd("command not found : ", 2);
	ft_putstr_fd(cmd, 2);
	ft_putstr_fd("\n", STDERR_FILENO);
	exit(0);
}

int	check_fd(t_exec *ex)
{
	if (ex->fd_in == -1)
	{
		ft_putstr_fd("le fichier n'existe pas\n", 2);
		return (1);
	}
	if (ex->fd_out == -1)
	{
		ft_putstr_fd("Erreur d'open\n", 2);
		return (1);
	}
	return (0);
}
