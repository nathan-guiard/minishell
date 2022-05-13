/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:24 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 18:06:08 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_a_nonl_option(char *str);

/*	Echo, -n implemente	*/
void	echo(char **args)
{
	int	i;
	int	has_a_nonl_option;

	i = 1;
	has_a_nonl_option = 0;
	if (!args)
		return (set_ret_value(0));
	if (args[0] == NULL)
		return (ft_putstr_fd("\n", 1), set_ret_value(0));
	while (is_a_nonl_option(args[i]) == TRUE)
		i++;
	if (i == 2)
		has_a_nonl_option = 1;
	while (args[i])
	{
		ft_putstr_fd(args[i], 1);
		if (args[i + 1] != NULL)
			ft_putstr_fd(" ", 1);
		i++;
	}
	if (has_a_nonl_option != 1)
		ft_putstr_fd("\n", 1);
	set_ret_value(0);
}

int	is_a_nonl_option(char *str)
{
	int	i;

	i = 1;
	if (!str || str[0] != '-')
		return (FALSE);
	while (str[i])
	{
		if (str[i] != 'n')
			return (FALSE);
		i++;
	}
	return (TRUE);
}
