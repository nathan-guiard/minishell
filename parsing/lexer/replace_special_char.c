/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_special_char.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:27:17 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/04 10:49:35 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		is_a_valid_space(char *line, int breakpoint);
char	replace_special_onechar(char truc);
int		is_a_valid_special_char(char *line, int breakpoint);
int		is_a_valid_dollar(char *line, int breakpoint);

/*	Retourne la meme ligne sauf que les caracteres speciaux
	genre < ou | sont remplaces si ils ne sont pas
	dans des quotes											*/
char	*replace_special_char(char *line)
{
	char	*res;
	int		i;

	if (!line)
		return (NULL);
	i = 0;
	res = malloc(sizeof(char) * (ft_strlen(line) + 1));
	if (!res)
		return (ft_putstr_fd(MERR_STR, 2), free(line), NULL);
	while (line[i])
	{
		if (is_a_valid_special_char(line, i) == TRUE)
			res[i] = replace_special_onechar(line[i]);
		else
			res[i] = line[i];
		i++;
	}
	res[i] = '\0';
	free(line);
	return (res);
}

/*	Retourne la macro VALID_<char> en fonction de char	*/
char	replace_special_onechar(char truc)
{
	t_symbol	res;
	char		omega_fraude[2];

	if (truc == ' ')
		return (VALID_SPACE);
	if (truc == '$')
		return (VALID_DOLLAR);
	omega_fraude[0] = truc;
	omega_fraude[1] = '\0';
	res = get_symbol(omega_fraude);
	if (res == sb_pipe)
		return (VALID_PIPE);
	if (res == red_in)
		return (VALID_REDIN);
	if (res == red_out)
		return (VALID_REDOUT);
	return (truc);
}

int	is_a_valid_special_char(char *line, int breakpoint)
{
	int		i;
	char	quote_type;

	if (is_a_valid_space(line, breakpoint) == TRUE
		|| is_a_valid_dollar(line, breakpoint) == TRUE)
		return (TRUE);
	if (get_onechar_symbol(line + breakpoint) == string
		|| line[breakpoint] == '$' || line[breakpoint] == ' ')
		return (FALSE);
	i = 0;
	quote_type = 0;
	while (line[i] != '\0' && i <= breakpoint)
	{
		if (line[i] == VALID_QUOTE || line[i] == VALID_DQUOTE)
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

int	is_a_valid_space(char *line, int breakpoint)
{
	int		i;
	char	quote_type;

	i = 0;
	quote_type = 0;
	if (breakpoint == 0 && line[0] == ' ')
		return (FALSE);
	if (line[breakpoint] != ' ')
		return (FALSE);
	while (line[i] != '\0' && i <= breakpoint)
	{
		if (line[i] == VALID_QUOTE || line[i] == VALID_DQUOTE)
		{
			if (line[i] == quote_type)
				quote_type = 0;
			else if (line[i] != quote_type && quote_type == 0)
				quote_type = line[i];
		}
		i++;
	}
	if (quote_type != 0)
		return (TRUE);
	return (FALSE);
}
