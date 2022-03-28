/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turn_env_into_tab.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 16:06:56 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:20:45 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//char	**turn_env_into_tab(void)
//{
//	int		len;
//	char	**res;
//	int		i;
//	t_list	*buff;
//	char	*line;

//	i = 0;
//	len = how_many_env();
//	res = malloc(sizeof(char *) * (len + 1));
//	buff = g_env;
//	while (buff->next != NULL)
//	{
//		line = ft_strdup(buff->content);
//		if (!line)
//		{
//			printf("malloc() error");
//			return ;
//		}
//		res[i] = line;
//		i++;
//		buff = buff->next;	
//	}
//	line = ft_strdup(buff->content);
//	if (!line)
//	{
//		printf("malloc() error");
//		return ;
//	}
//	res[len] = line;
//	return (res);
//}