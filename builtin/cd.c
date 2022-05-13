/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 17:42:03 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 15:24:54 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cd(char **args)
{
	char	*home;

	if (!args)
		return ;
	home = ft_getenv("HOME");
	if (args[1] == NULL || args[1][0] == '~' )
		chdir(home);
	else
		chdir(args[1]);
	free(home);
}
