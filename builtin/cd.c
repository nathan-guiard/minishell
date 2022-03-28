/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:42:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:14:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char **args)
{
	char	*home;

	home = getenv("HOME");
	if (!args)
		return ;
	if (args[0] == NULL || args[0][0] == '~' )
		chdir(home);
	else
		chdir(args[0]);
}
