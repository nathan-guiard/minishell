/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   api_last_red_in.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:33:34 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 11:30:19 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*	Renvoie nom du dernier fichier de redirection in ou
	NULL si il y en a pas.
	Si un heredoc a ete detecte, renvoie HEREDOC_STRING
	En gros c'est le fichier qu'on doit lire
	A NE PAS FREE										*/
char	*api_last_red_in(t_lexer *list)
{
	t_lexer	*buff;
	char	*last;

	last = NULL;
	buff = list;
	while (buff)
	{
		if (buff->symbol == red_in && buff->next)
			last = buff->next->content;
		if (buff->symbol == heredoc)
			return (HEREDOC_STRING);
		buff = buff->next;
	}
	return (last);
}
