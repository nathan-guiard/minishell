/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_env_into_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:56 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 15:52:56 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**turn_env_into_tab(void)
{
	int		len;
	char	**res;
	int		i;
	t_list	*buff;
	char	*line;

	i = 0;
	len = ft_lstsize(g_env);
	res = malloc(sizeof(char *) * (len + 1));
	buff = g_env;
	while (buff)
	{
		line = ft_strdup(buff->content);
		if (!line)
		{
			ft_putstr_fd(MERR_STR, 2);
			return (NULL);
		}
		res[i] = line;
		i++;
		buff = buff->next;
	}
	res[len] = NULL;
	return (res);
}
