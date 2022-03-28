/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 11:07:30 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 15:16:30 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(char **args)
{
	t_list	*buff;

	if (!g_env)
		return ;
	if (args == NULL || args[0] == NULL)
	{
		buff = g_env;
		while (buff->next != NULL)
		{
			printf("%s\n", (char *)buff->content);
			buff = buff->next;
		}
		printf("%s\n", (char *)buff->content);
	}
}
