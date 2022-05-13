/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_full_command.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 14:43:31 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/13 17:24:31 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	how_long(t_lexer *list);

/*	Donne le tableau de tableau "commande" pour execve
	il faut le FREE /!\									*/
char	**api_full_command(t_lexer *list)
{
	char	**res;
	t_lexer	*buff;
	int		i;
	int		len;

	i = 0;
	len = how_long(list);
	if (len == 0)
		return (NULL);
	res = ft_calloc(sizeof(char *), (len + 1));
	if (!res)
		return (NULL);
	buff = list;
	while (buff)
	{
		if (buff->symbol == command || buff->symbol == argument)
		{
			res[i] = ft_strdup(buff->content);
			i++;
		}
		buff = buff->next;
	}
	return (res);
}

static int	how_long(t_lexer *list)
{
	t_lexer	*buff;
	int		res;

	res = 0;
	buff = list;
	while (buff)
	{
		if (buff->symbol == command || buff->symbol == argument)
			res++;
		buff = buff->next;
	}
	return (res);
}
