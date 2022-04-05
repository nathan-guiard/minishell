/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_heredoc_delimiter.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:34:19 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 17:38:23 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Renvoie la chaine de caractere du delimiteur
	Renvoie NULL si il n'y en a pas
	A NE PAS FREE									*/
char	*api_heredoc_delimiter(t_lexer *list)
{
	t_lexer	*buff;

	buff = list;
	while (buff)
	{
		if (buff->symbol == delimiter)
			return ((char *)buff->content);
		buff = buff->next;
	}
	return (NULL);
}