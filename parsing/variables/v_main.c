/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:16:54 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/15 13:25:03 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

char *test(char *line)
{
	return (replace_variables(line));
}

/*	Remplace les variables par leur valeur dans l'environnement
	Retour la ligne cahngee ou alors retourne S_ERR en cas d'erreur	*/
char *replace_variables(char *line)
{
	int	i;
	int ret;

	ret = 0;
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '$')
		{
			ret = is_a_valid_env(line, i);
			if (ret == M_ERR)
				return (printf("Main: return S_MERR\n"), S_MERR);
			else if (ret == TRUE)
			{
				line = replace_variable_by_content(line, i);
				if (ft_strcmp(S_ERR, line) == 0)
					return (printf("Main: retour S_ERR\n"), S_ERR);
				i = 0;
			}
			else if (ret == FALSE)
			{
				line = replace_variable_by_nothing(line, i);
				if (ft_strcmp(S_ERR, line) == 0)
					return (S_ERR);
				i = 0;
			}
		}
		if ((size_t)i < ft_strlen(line))
			i++;
	}
	return (line);
}

int	is_a_valid_env(char *line, int i)
{
	char *test;
	char *ptr;
	int	save;
	int	j;

	i++;
	save = i;
	while (line[i] != '\0' && line[i] != '\f' && line[i] != '\t'
		&& line[i] != '\n' && line[i] != '\r' && line[i] != '\v'
		&& line[i] != ' ' && line[i] != '$')
		i++;
	if (i - save == 0)
		return (ALONE);
	test = malloc(sizeof(char) * ((i - save) + 1));
	if (!test)
		return (M_ERR);
	j = 0;
	while (save + j < i)
	{
		test[j] = line[save + j];
		j++;
	}
	test[j] = '\0';
	test = remove_brackets(test);
	//printf("test: %s\n", test);
	ptr = getenv(test);
	free(test);
	if (ptr)
		return (TRUE);
	return (FALSE);	
}

int	where_is_end_var(char *line, int start_var)
{
	int		i;
	char	search;

	i = start_var;
	if (line[i + 1] == '{')
	{
		i++;
		search = '}';
	}
	else
		search = ' ';
	i++;
	while (line[i] != search && line[i])
	{
		if (line[i] == '\f' || line[i] == '\t' || line[i] == '\n'
			|| line[i] == '\r' || line[i] == '\v' || line[i] == '$')
			break;
		i++;
	}
	if (search == '}' && line[i] != search)
		return (P_ERR);
	return (i);
}


char	*remove_brackets(char *tab)
{
	int	start;
	int	end;
	char	*to_free;

	if (tab[0] != '{')
		return (tab);
	start = 1;
	end = ft_strlen(tab) - 2;
	to_free = tab;
	tab = ft_substr(tab, start, end);
	free(to_free);
	return (tab);	
}