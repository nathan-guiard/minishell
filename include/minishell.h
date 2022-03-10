/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:00:38 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 07:36:32 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>

char	*prompt(void);

/* Built-in */

void	echo(char **args);
void	cd(char **args);
void	pwd(char **args);
void	clear(void);

/* Utils */

void	free_tabtab(char **tab);
void	catch_signals(void);

/* Parsing */

char	**remove_command_name(char **);