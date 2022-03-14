/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   variables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 12:16:54 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/14 13:23:15 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	is_a_valid_env(char *line, int i);
static char	**replace_variable_by_content(char *line, int i);

/*	Remplace les variables par leur valeur dans l'environnement */
char *remove_variables(char *line)
{
	int	i;
	int ret;

	ret = 0;
	i = 0;
	while (line[i])
	{
		ret = is_a_valid_env(line, i);
		if (line[i] == '$' && ret == ERR)
			printf("malloc() error");
		else if (line[i] == '$' && ret == TRUE)
			line = replace_variable_by_content(line, i);
		else if (line[i] == '$' && ret == FALSE)
			line = replace_variable_by_nothing(line, i);
		i++;
	}
	return (line);
}

static int	is_a_valid_env(char *line, int i)
{
	char *test;
	char *ptr;
	int	save;
	int	j;

	i++;
	save = i;
	while (line[i] != '\0' && line[i] != '\f' && line[i] != '\t'
		&& line[i] != '\n' && line[i] != '\r' && line[i] != '\v'
		&& line[i] != ' ')
		i++;
	if (save - i == 0)
		return (ALONE);
	test = malloc(sizeof(char) * ((save - i) + 1));
	if (!test)
		return (ERR);
	j = 0;
	while (save + j < i)
	{
		test[j] = line[save + j];
		j++;
	}
	test[j] = '\0';
	ptr = getenv(test);
	free(test);
	if (ptr)
		return (TRUE);
	return (FALSE);	
}

