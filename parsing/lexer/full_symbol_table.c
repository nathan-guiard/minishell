/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_symbol_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 10:06:50 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 14:31:46 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_lexer	*transform_tabs_into_nodes(char **split);
static char		*replace_non_writable_spaces(char *tab);
static char		**put_spaces_again(char **tab);
static int		quotes_closed(char *line);

/*	Transforme la ligne en une liste "symbol table"
	Gere bien char speciaux dans ou hors des quotes
	Check pas les pipes	(division)					*/
t_lexer	*full_symbol_table(char *line)
{
	char	**splitted;
	t_lexer	*res;

	if (quotes_closed(line) == FALSE)
		return (ft_putstr_fd("Syntax error\n", 2), free(line), NULL);
	line = replace_quotes(line);
	line = replace_special_char(line);
	if (!line)
		return (NULL);
	line = replace_variables(line);
	if (!line)
		return (NULL);
	splitted = ft_split(line, ' ');
	if (!splitted)
		return (ft_putstr_fd(MERR_STR, 2), free(line), NULL);
	free(line);
	splitted = put_spaces_again(splitted);
	res = transform_tabs_into_nodes(splitted);
	quote_handling(&res);
	split_the_unsplitted(&res);
	if (check_error_full_string(res) == TRUE)
		return (ft_lexerclear(&res, free),
			ft_putstr_fd("Syntax error.\n", 2), NULL);
	return (res);
}

/*	Transforme chaques tableaux du split en maillons pour la liste	*/
static t_lexer	*transform_tabs_into_nodes(char **split)
{
	t_lexer	*res;
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
	while (tab[i])
	{
		tab[i] = replace_non_writable_spaces(tab[i]);
		i++;
	}
	return (tab);
}

/*	Remet les espaces mais dans un tableau	*/
static char	*replace_non_writable_spaces(char *tab)
{
	int	i;

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

static int	quotes_closed(char *line)
{
	int		i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	while (line[i] != 0)
	{
		if (line[i] == '\'' || line[i] == '\"')
		{
			if (line[i] == quote_type)
				quote_type = 0;
			else if (line[i] != quote_type && quote_type == 0)
				quote_type = line[i];
		}
		i++;
	}
	if (quote_type != 0)
		return (FALSE);
	return (TRUE);
}
