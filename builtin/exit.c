/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 19:32:04 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 18:38:26 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	exit_with_args(char **args);
static int	has_only_digit(char *s);

/*	exit avec exit_value, si il y a des args alors
	reproduit le comportement de bash				*/
void	ft_exit(int exit_value, char **args)
{
	if (args && args[1] != NULL)
		exit_with_args(args);
	else
	{
		ft_lstclear(&g_env, free);
		rl_clear_history();
		exit(exit_value);
	}
}

/*	Exit en mode ligne de commande, prototype void(char **) pour le tableau de
	pointeur sur fonctions													*/
void	ft_exit_builtin(char **args)
{
	ft_putstr_fd("exit\n", 2);
	ft_exit(0, args);
}

/*	exit modulo 256 car bash le fait comme ca 
	Je me tate a laisser les exit de STDOUT			*/
static void	exit_with_args(char **args)
{
	int	i;
	int	atoi;

	i = 1;
	while (args[i])
		i++;
	if (i > 2)
	{
		ft_putstr_fd("exit: too many arguments\n", 2);
		return ;
	}
	if (has_only_digit(args[0]) == FALSE)
	{
		ft_putstr_fd("exit: numeric argument required\n", 2);
		exit(2);
	}
	atoi = ft_atoi(args[0]);
	free_tabtab(args);
	exit(atoi % 256);
}

/* Check si il y a que des nombres dans une string	*/
static int	has_only_digit(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (ft_isdigit(s[i]) == 0)
			return (FALSE);
		i++;
	}
	return (TRUE);
}
