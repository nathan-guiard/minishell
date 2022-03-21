/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_symbol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 14:47:43 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 13:34:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

t_symbol	get_onechar_symbol(char *line);

t_symbol	get_symbol(char *line)
{
	if (ft_strlen(line) == 1)
		return (get_onechar_symbol(line));
	if (ft_strcmp(line, "<<") == 0)
		return (heredoc);
	if (ft_strcmp(line, ">>") == 0)
		return (append);
	if (ft_strchr(line, '/') != NULL)
		return (path);
	if (is_a_builtin(line) == TRUE)
		return (sb_builtin);
	return (string);
}

t_symbol	get_onechar_symbol(char *line)
{
	if (line[0] == '<')
		return (red_in);
	if (line[0] == '>')
		return (red_out);
	if (line[0] == VALID_PIPE)
		return (sb_pipe);
	if (line[0] == '\"')
		return (d_quote);
	if (line[0] == '\'')
		return (quote);
	return (string);
}