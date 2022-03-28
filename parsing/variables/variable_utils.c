/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 09:09:01 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/28 13:29:21 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

/*	Check si la variable existe	*/
int	is_a_valid_env(char *line, int i)
{
	char	*test;
	char	*ptr;
	int		save;
	int		j;

	i++;
	save = i;
	while (line[i] && (line[i] <= 9 && line[i] >= 13) && line[i] != VALID_SPACE
		&& line[i] != VALID_DOLLAR && line[i] != '\"' && line[i] != ' ')
		i++;
	//if (i - save == 0)
		//return (ALONE);
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
	ptr = ft_getenv(test);// a remplacer par ft_getenv
	printf("getenv dans is_a_valid_env; %s\n", ptr);
	free(test);
	if (ptr && ft_strcmp(ptr, S_ERR) != 0)
		return (free(ptr), TRUE);
	return (free(ptr), FALSE);
}

/*	Trouve l'indice de la fin de la variable	*/
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
			|| line[i] == '\r' || line[i] == '\v' || line[i] == VALID_DOLLAR
			|| line[i] == '\"' || line[i] == '\'')
			break ;
		i++;
	}
	if (search == '}' && line[i] != search)
		return (P_ERR);
	if (search == '}')
		return (i + 1);
	return (i);
}

/*	Enleve les {} d'une chaine (*variable shell dans notre cas)	*/
char	*remove_brackets(char *tab)
{
	int		start;
	int		end;
	char	*to_free;

	if (tab[0] != '{')
		return (tab);
	start = 1;
	end = ft_strlen(tab) - 2;
	to_free = tab;
	tab = ft_substr(tab, start, end);
	free(to_free);
	printf("remove brackets: %s\n", tab);
	return (tab);
}
