/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variable_replace.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:16:54 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/06 16:41:22 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "variables.h"

char	*change_the_variable(char *line, int *i);

/*	Remplace les variables par leur valeur dans l'environnement
	Retour la ligne changee ou alors retourne S_ERR/S_MERR en cas d'erreur	*/
char	*replace_variables(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == VALID_DOLLAR)
			line = change_the_variable(line, &i);
		if ((size_t)i < ft_strlen(line))
			i++;
	}
	return (line);
}

/*	Prend la premiere partie avant et apres la variable qu'on veut changer
	puis prend la valeur de la varaible dans l'env et join le tout			*/
char	*replace_variable_by_content(char *line, int start_var)
{
	int		end_var;
	char	*res;
	char	*part_one;
	char	*part_two;

	end_var = where_is_end_var(line, start_var);
	part_one = ft_substr(line, 0, start_var);
	if (!part_one)
		return (S_ERR);
	part_two = ft_substr(line, end_var, INT_MAX);
	line = only_content(line, start_var);
	res = join(part_one, line);
	if (!res)
		return (S_ERR);
	res = join(res, part_two);
	if (!res)
		return (S_ERR);
	if (part_two)
		free(part_two);
	if (line)
		free(line);
	return (res);
}

/*	Ne recupere que le contenu de la variable qui se trouve a l'indice
	start_var de la chaine line												*/
char	*only_content(char *line, int start_var)
{
	char	*to_free;
	char	*sub;
	char	*no_brackets;

	if (line[start_var] == '{')
		start_var++;
	sub = ft_substr(line, start_var + 1,
			where_is_end_var(line, start_var) - start_var - 1);
	to_free = line;
	no_brackets = remove_brackets(sub);
	line = ft_getenv(no_brackets);
	if (to_free)
		free(to_free);
	if (ft_strcmp(sub, no_brackets) == 0)
		free(sub);
	return (line);
}

/*	Join ce qu'il y a avant et apres la variable inexistante
	avec NOTHING entre les deux									*/
char	*replace_variable_by_nothing(char *line, int start_var)
{
	int		end_var;
	char	*res;
	char	*part_one;
	char	*part_two;

	end_var = where_is_end_var(line, start_var);
	part_one = ft_substr(line, 0, start_var);
	part_one = join(part_one, "\022");
	if (!part_one)
		return (S_ERR);
	part_two = ft_substr(line, end_var, INT_MAX);
	res = join(part_one, part_two);
	free(part_two);
	free(line);
	return (res);
}

char	*change_the_variable(char *line, int *i)
{
	int	ret;

	ret = is_a_valid_env(line, *i);
	if (ret == M_ERR)
		return (S_MERR);
	else if (ret == TRUE)
	{
		line = replace_variable_by_content(line, *i);
		if (ft_strcmp(S_ERR, line) == 0)
			return (S_ERR);
		*i = 0;
	}
	else if (ret == FALSE)
	{
		line = replace_variable_by_nothing(line, *i);
		if (ft_strcmp(S_ERR, line) == 0)
			return (S_ERR);
		*i = 0;
	}
	return (line);
}
