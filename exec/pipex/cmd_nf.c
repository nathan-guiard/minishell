/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_nf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:04:36 by tgeorgin          #+#    #+#             */
/*   Updated: 2022/05/11 18:09:44 by tgeorgin         ###   ########.fr       */
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