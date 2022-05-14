/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:09:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 14:36:42 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

int			what_is_i(char *line, int i);
static int	if_check(char c);

/*	Check si la variable existe	*/
int	is_a_valid_env(char *line, int i)
{
	char	*test;
	char	*ptr;
	int		save;
	int		j;

	i++;
	save = i;
	i = what_is_i(line, i);
	test = malloc(sizeof(char) * ((i - save) + 1));
	if (!test)
		return (ft_putstr_fd(MERR_STR, 2), FALSE);
	j = 0;
	while (save + j < i)
	{
		test[j] = line[save + j];
		j++;
	}
	test[j] = '\0';
	test = remove_brackets(test);
	ptr = ft_getenv(test);
	free(test);
	if (ptr)
		return (free(ptr), TRUE);
	return (free(ptr), FALSE);
}

/*	Trouve l'indice de la fin de la variable	*/
int	where_is_end_var(char *line, int start_var)
{
	int		i;
	char	search;

	i = start_var;
	search = ' ';
	if (line[i + 1] == '{')
	{
		i++;
		search = '}';
	}
	i++;
	while (line[i] != search && line[i])
	{
		if (if_check(line[i]) == TRUE)
			break ;
		i++;
	}
	if (search == '}' && line[i] != search)
		return (start_var);
	if (search == '}')
		return (i + 1);
	return (i);
}

/*	Enleve les {} d'une chaine (*variable shell dans notre cas)	*/
char	*remove_brackets(char *tab)
{
	int		end;
	char	*to_free;

	if (!tab)
		return (NULL);
	if (tab[0] != '{')
		return (tab);
	end = ft_strlen(tab) - 2;
	to_free = tab;
	tab = ft_substr(tab, 1, end);
	if (!tab)
		return (ft_putstr_fd(MERR_STR, 2), free(to_free), NULL);
	free(to_free);
	return (tab);
}

int	what_is_i(char *line, int i)
{
	while (line[i] && !(line[i] <= 9 && line[i] >= 13) && line[i] != VALID_SPACE
		&& line[i] != VALID_DOLLAR && line[i] != VALID_DQUOTE && line[i] != ' '
		&& line[i] != '$' && line[i] != VALID_REDOUT
		&& line[i] != VALID_REDIN && line[i] != VALID_PIPE && line[i] != '=')
			i++;
	return (i);
}

static int	if_check(char c)
{
	if (c == '\f' || c == '\t' || c == '\n'
		|| c == '\r' || c == '\v' || c == VALID_DOLLAR
		|| c == VALID_DQUOTE || c == '$'
		|| c == VALID_REDIN || c == VALID_REDOUT
		|| c == VALID_PIPE || c == VALID_APPEND || c == VALID_HEREDOC
		|| c == '=')
		return (TRUE);
	return (FALSE);
}
