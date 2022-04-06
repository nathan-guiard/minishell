/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_every_red_in.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 14:00:39 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:25:59 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	nb_of_red_in(t_lexer *list);

/*	Renvoie un tableau de tableaux avec tous les fichiers de redirections in.
	A FREE																	  */
char	**api_every_red_in(t_lexer *list)
{
	int		count;
	char	**res;
	int		i;
	t_lexer	*buff;

	i = 0;
	count = nb_of_red_in(list);
	res = ft_calloc(sizeof(char *), (count + 1));
	if (!res)
		return (NULL);
	buff = list;
	while (buff)
	{
		if (buff->symbol == red_in_file)
		{
			res[i] = ft_strdup(buff->content);
			i++;
		}
		buff = buff->next;
	}
	res[i] = NULL;
	return (res);
}

int	nb_of_red_in(t_lexer *list)
{
	int		i;
	t_lexer	*buff;

	i = 0;
	buff = list;
	while (buff)
	{
		if (buff->symbol == red_in_file)
			i++;
		buff = buff->next;
	}
	return (i);
}
