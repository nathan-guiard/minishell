/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:24 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:14:40 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Echo, -n implemente, pas de gestion de $*/
void	echo(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	if (args[0] == NULL)
	{
		printf("\n");
		return ;
	}
	if (ft_strcmp(args[0], "-n") == 0)
		i++;
	while (args[i])
	{
		if (!(i == 0 || (i == 1 && ft_strcmp(args[0], "-n") == 0)))
			printf(" ");
		printf("%s", args[i]);
		i++;
	}
	if (ft_strcmp(args[0], "-n") != 0)
		printf("\n");
}
