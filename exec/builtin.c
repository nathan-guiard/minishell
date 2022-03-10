/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 12:45:05 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 12:51:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin(char **command)
{
	builtin_fnc	fnc;

	if (is_a_builtin(command[0]) != FALSE)
	{
		if (is_a_builtin(command[0]) == TRUE)
		{
			fnc = get_builtin_fnc(command[0]);
			command = remove_command_name(command);
			fnc(command);
			return (TRUE);
		}
		return (ERR);
	}
	else
		return (FALSE);
}