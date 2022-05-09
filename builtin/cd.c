/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:42:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/09 10:31:26 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char **args)
{
	char	*home;

	if (!args)
		return ;
	home = ft_getenv("HOME");
	if (args[0] == NULL || args[0][0] == '~' )
		chdir(home);
	else
		chdir(args[0]);
	free(home);
}
