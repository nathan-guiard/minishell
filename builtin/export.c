/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:08:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 15:01:43 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_nothing(void);

void	export(char **args)
{
	if (!args || !args[1])
		ft_export_nothing();
	printf("export not supported\n");
}

void	ft_export_nothing(void)
{
	t_list	*buff;

	buff = g_env;
	while (buff)
	{
		printf("declare -x %s\n", (char *)buff->content);
		buff = buff->next;
	}
}
