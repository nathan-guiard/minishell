/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_symbol_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:06:50 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 13:53:26 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_lexer *transform_tabs_into_nodes(char **split);
t_lexer	*get_nodes(char *tab);
char *replace_non_writable_spaces(char *tab);
char	**put_spaces_again(char **tab);

/*	Transforme la ligne en une liste "symbol table"
	Check pas les pipes
	Check pas les separations collees comme "cat|ls"				*/
t_lexer	*full_symbol_table(char *line)
{
	char **splitted;
	t_lexer	*res;

	line = replace_pipe_and_spaces(line);
	splitted = ft_split(line, ' ');
	splitted = put_spaces_again(splitted);
	res = transform_tabs_into_nodes(splitted);
	//quote_handling(&res);
	return (res);
}

/*	Transforme chaques tableaux du split en maillons pour la liste	*/
t_lexer *transform_tabs_into_nodes(char **split)
{
	t_lexer *res;
	t_lexer	*node;
	int		i;

	i = 0;
	res = NULL;
	node = NULL;
	while (split[i] != NULL)
	{
		node = ft_lexernew(ft_strdup(split[i]), get_symbol(split[i]));
		ft_lexeradd_back(&res, node);
		i++;
	}
	free_tabtab(split);
	return (res);
}

char	**put_spaces_again(char **tab)
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

char *replace_non_writable_spaces(char *tab)
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