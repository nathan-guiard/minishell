/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:08:45 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 12:26:50 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export_nothing(void);
void	real_export(char **args);

void	export(char **args)
{
	if (!args || !args[1])
	{
		ft_export_nothing();
		return ;
	}
	unset(args);
	real_export(args);
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

void	real_export(char **args)
{
	int		i;
	t_list	*node;

	i = 1;
	while (args[i])
	{
		node = ft_lstnew(ft_strdup(args[i]));
		ft_lstadd_back(&g_env, node);
		printf("exported %s\n", args[i]);
		i++;
	}
}