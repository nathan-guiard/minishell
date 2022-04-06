/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:24 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:13:46 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_a_nonl_option(char *str);

/*	Echo, -n implemente, pas de gestion de $*/
void	echo(char **args)
{
	int	i;
	int	has_a_nonl_option;

	i = 1;
	has_a_nonl_option = 0;
	if (!args)
		return ;
	if (args[0] == NULL)
	{
		printf("\n");
		return ;
	}
	while (is_a_nonl_option(args[i]) == TRUE)
		i++;
	if (i != 1)
		has_a_nonl_option = 1;
	while (args[i])
	{
		if (!(i == 1 || has_a_nonl_option == 1))
			printf(" ");
		printf("%s", args[i]);
		i++;
	}
	if (has_a_nonl_option != 1)
		printf("\n");
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