/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_symbol_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:06:50 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/23 08:51:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lexer	*transform_tabs_into_nodes(char **split);
static char		*replace_non_writable_spaces(char *tab);
static char		**put_spaces_again(char **tab);

/*	Transforme la ligne en une liste "symbol table"
	Gere bien les espaces dans les quotes
	Check pas les pipes
	Check pas les separations collees comme "cat|ls"				*/
t_lexer	*full_symbol_table(char *line)
{
	char **splitted;
	t_lexer	*res;

	line = replace_special_char(line);
	splitted = ft_split(line, ' ');
	free(line);
	splitted = put_spaces_again(splitted);
	res = transform_tabs_into_nodes(splitted);
	quote_handling(&res);
	split_the_unsplitted(&res);
	return (res);
}

/*	Transforme chaques tableaux du split en maillons pour la liste	*/
static t_lexer *transform_tabs_into_nodes(char **split)
{
	t_lexer *res;
	t_lexer	*node;
	int		i;

	i = 0;
	res = NULL;
	node = NULL;
	while (split[i] != NULL)
	{
		node = ft_lexernew(ft_strdup(split[i]), get_symbol_replaced(split[i]));
		ft_lexeradd_back(&res, node);
		i++;
	}
	free_tabtab(split);
	return (res);
}

/*	Remet les espaces du doubles tableaux qui etaient des VALID_SPACE	*/
static char	**put_spaces_again(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		tab[i] = replace_non_writable_spaces(tab[i]);
		i++;
	}
	return (tab);
}

/*	Remet les espaces mais dans un tableau	*/
static char *replace_non_writable_spaces(char *tab)
{
	int i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i])
	{
		if (tab[i] == VALID_SPACE)
			tab[i] = SPACE;
		i++;
	}
	return (tab);
}