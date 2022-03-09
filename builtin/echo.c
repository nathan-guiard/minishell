/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 16:44:24 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/09 16:51:16 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	echo(char **args)
{
	int i;

	i = 0;
	if (!args)
		return ;
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