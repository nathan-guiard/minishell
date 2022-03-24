/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:47:43 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/24 10:55:33 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_symbol	get_onechar_symbol(char *line);
t_symbol	get_onechar_symbol_replaced(char *line);

t_symbol	get_symbol(char *line)
{
	if (!line)
		return (string);
	if (ft_strcmp(line, "<<") == 0)
		return (heredoc);
	if (ft_strcmp(line, ">>") == 0)
		return (append);
	if (is_a_builtin(line) == TRUE)
		return (sb_builtin);
	if (get_onechar_symbol(line) != string)
		return (get_onechar_symbol(line));
	return (string);
}

t_symbol	get_onechar_symbol(char *line)
{
	if (line[0] == '<')
		return (red_in);
	if (line[0] == '>')
		return (red_out);
	if (line[0] == '|')
		return (sb_pipe);
	if (line[0] == '\"')
		return (d_quote);
	if (line[0] == '\'')
		return (quote);
	return (string);
}

t_symbol	get_symbol_replaced(char *line)
{
	if (!line)
		return (string);
	if (ft_strcmp(line, "\005\005") == 0)
		return (heredoc);
	if (ft_strcmp(line, "\006\006") == 0)
		return (append);
	if (is_a_builtin(line) == TRUE)
		return (sb_builtin);
	if (get_onechar_symbol_replaced(line) != string)
		return (get_onechar_symbol_replaced(line));
	return (string);
}

t_symbol	get_onechar_symbol_replaced(char *line)
{
	if (line[0] == VALID_REDIN)
		return (red_in);
	if (line[0] == VALID_REDOUT)
		return (red_out);
	if (line[0] == VALID_PIPE)
		return (sb_pipe);
	if (line[0] == '\"')
		return (d_quote);
	if (line[0] == '\'')
		return (quote);
	return (string);
}