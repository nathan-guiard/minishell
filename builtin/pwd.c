/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:54:20 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 15:26:00 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **args)
{
	char	*path;

	if (args == NULL || args[1] == NULL)
	{
		path = malloc(sizeof(char) * 10000);
		if (!path)
			ft_putstr_fd("malloc() error", 2);
		if (getcwd(path, 9999) == NULL)
		{
			free(path);
			return ;
		}
		printf("%s\n", path);
		free(path);
	}
	else
		ft_putstr_fd("pwd: too many arguments\n", 2);
}
