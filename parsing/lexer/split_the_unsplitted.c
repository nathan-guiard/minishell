/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_the_unsplitted.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:53:18 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 17:21:28 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		devide_the_node(t_lexer **list, void *to_be_splitted);
t_lexer			*new_splitted_list(char *line);

/*	Decolle les maillons colles comme "cat|ls"
	Necessite d'ajouter des maillons a l'interieur
	de la liste										*/
void	split_the_unsplitted(t_lexer **list)
{
	t_lexer	*buff;

	if (!list || !(*list))
		return ;
	buff = *list;
	while (buff)
	{
		if (symbol_change(buff->content, 0) != (int)ft_strlen(buff->content))
		{
			devide_the_node(list, buff);
			buff = *list;
		}
		else
			buff = buff->next;
	}
}

/*	Split le maillon en plusieurs puis l'insere apres le maillon d'avant */
static void	devide_the_node(t_lexer **list, void *to_be_splitted)
{
	t_lexer	*to_insert;
	t_lexer	*buff;
	t_lexer	*before;

	buff = *list;
	before = NULL;
	while (buff)
	{
		if (buff == to_be_splitted)
		{
			to_insert = new_splitted_list(buff->content);
			ft_lexerinsert(list, to_insert, before);
			ft_lexerpop(list, buff);
			ft_lexerdelone(buff, free);
			buff = to_insert;
		}
		else
		{
			before = buff;
			buff = buff->next;
		}
	}
}

t_lexer	*new_splitted_list(char *line)
{
	t_lexer	*res;
	t_lexer	*node;
	int		i;
	int		next;
	char	*new_content;

	if (!line)
		return (NULL);
	i = 0;
	res = NULL;
	node = NULL;
	while (line[i])
	{
		next = symbol_change(line, i);
		new_content = ft_substr(line, i, next - i);
		node = ft_lexernew(new_content, get_symbol_replaced(new_content));
		ft_lexeradd_back(&res, node);
		i = next;
		if (i > (int)ft_strlen(line))
			break ;
	}
	return (res);
}

/*	Retourne l'index du changement de symbole
	Si deux symboles separateurs se suivent alors il envoie 
	le moment ou ca change de sep							*/
int	symbol_change(char *line, int start)
{
	t_symbol	curr;
	t_symbol	to_test;
	int			i;
	char		nitro_fraude[3];

	ft_bzero(nitro_fraude, 3);
	nitro_fraude[0] = line[start];
	if (line[start] && line[start + 1] != '\0')
		nitro_fraude[1] = line[start + 1];
	curr = get_symbol_replaced(nitro_fraude);
	i = start + sizeof_sep(curr);
	while (line[i])
	{
		nitro_fraude[0] = line[i];
		if (line[i + 1] != '\0')
			nitro_fraude[1] = line[i + 1];
		to_test = get_symbol_replaced(nitro_fraude);
		if (to_test != curr || (is_a_symbol_sep(to_test) == TRUE
				&& to_test == curr && (i - start >= (int)sizeof_sep(curr))))
			break ;
		i++;
	}
	return (i);
}

/*	Retourne la taille de char que fait un symbole,
	0 si la taille est indefinie					*/
size_t	sizeof_sep(t_symbol symbol)
{
	if (symbol == heredoc || symbol == append)
		return (2);
	if (symbol == red_in
		|| symbol == red_out
		|| symbol == quote
		|| symbol == d_quote
		|| symbol == sb_pipe)
		return (1);
	else
		return (0);
}
