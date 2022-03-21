/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quote_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:57:48 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 16:52:41 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*neutralize_the_quote(char *tab);
char	*fill_the_quote_void(char *tab);

/*	Change les parties quoted en un seul maillon quoted_string
	Les maillons quoted_string sont a prendre tels quel et a
	ne surtout pas changer le contenu							*/
void	quote_handling(t_lexer **list)
{
	t_lexer	*buff;
	void	*tmp;

	if (!list)
		return ;
	buff = *list;
	while (buff)
	{
		tmp = buff->content;
		buff->content = neutralize_the_quote(buff->content);
		buff->content = fill_the_quote_void(buff->content);
		if (tmp != buff->content)
		{
			buff->symbol = quoted_string;
			printf("Something has changed\n");
		}
		else
			printf("Nothing has changed\n");
		buff = buff->next;
	}
}

/*	Change toutes les quotes valides par REPLACE_THIS_HOLE		*/
char	*neutralize_the_quote(char *tab)
{
	int i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	while (tab[i])
	{
		if (tab[i] == '\'' || tab[i] == '\"')
		{
			if (quote_type == 0)
			{
				quote_type = tab[i];
				tab[i] = REPLACE_THIS_HOLE;
			}
			else if (quote_type == tab[i])
			{
				quote_type = 0;
				tab[i] = REPLACE_THIS_HOLE;
			}
		}
		i++;
	}
	fill_the_quote_void(tab);
	return (tab);
}

char	*fill_the_quote_void(char *tab)
{
	int		i;
	char	*to_free;

	i = 0;
	if (!tab)
		return (NULL);
	if (ft_strchr(tab, REPLACE_THIS_HOLE) == NULL)
		return (tab);
	while (tab[i])
	{
		if (tab[i] == REPLACE_THIS_HOLE)
		{
			to_free = tab;
			tab = ft_strrm_index(tab, i);
			if (tab != to_free && to_free != NULL)
				free(to_free);
			i--;
		}
		i++;
	}
	return (tab);
}