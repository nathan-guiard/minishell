/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_quotes_and_pipe.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:27:17 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 13:30:11 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//int	is_a_valid_quote(char *line, int breakpoint);
//int	is_a_valid_dquote(char *line, int breakpoint);

char *replace_pipe(char *line)
{
	char	*res;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!res)
		return (NULL);
	while (line[i])
	{
		if (is_a_valid_pipe(line, i) == TRUE)
			res[i] = VALID_PIPE;
		else
			res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

//int	is_a_valid_quote(char *line, int breakpoint)
//{
//	int	i;
//	int	quote;

//	i = 0;
//	quote = 0;
//	if (breakpoint == 0 && line[0] == '\'')
//		return (TRUE);
//	if (line[breakpoint] != '\'')
//		return FALSE;
//	while (line[i] != '\0' && i <= breakpoint)
//	{
//		if (line[i] == '\"')
//			quote++;
//		i++;
//	}
//	if (quote % 2 == 0)
//		return (TRUE);
//	return (FALSE);
//}

//int	is_a_valid_dquote(char *line, int breakpoint)
//{
//	int	i;
//	int	quote;

//	i = 0;
//	quote = 0;
//	if (breakpoint == 0 && line[0] == '\"')
//		return (TRUE);
//	if (line[breakpoint] != '\"')
//		return FALSE;
//	while (line[i] != '\0' && i <= breakpoint)
//	{
//		if (line[i] == '\'')
//			quote++;
//		i++;
//	}
//	if (quote % 2 == 0)
//		return (TRUE);
//	return (FALSE);
//}

int	is_a_valid_pipe(char *line, int breakpoint)
{
	int		i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	if (breakpoint == 0 && line[0] == '|')
		return (FALSE);
	if (line[breakpoint] != '|')
		return FALSE;
	while (line[i] != '\0' && i <= breakpoint)
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