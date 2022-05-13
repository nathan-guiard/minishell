/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 18:54:20 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 18:03:37 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pwd(char **args)
{
	char	*path;

	if (!args)
		return ;
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
	set_ret_value(0);
}
