/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/21 11:38:14 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_list *g_env;

int main(int argc, char **argv, char **env)
{
	char		*line;
	t_lexer		*node;

	(void)argc;
	(void)argv;
	(void)env;
	//catch_signals();
	while (1)
	{
		line = prompt();
		if (line)
		{
			node = full_symbol_table(line);
			t_lexer *save = node;
			while (node != NULL)
			{
				set_layout_printf(C_GREEN, C_RESET, C_BOLD);
				printf("Content:%s\nsymbol:%d\nnext:%p\n\n", node->content, node->symbol, node->next);
				set_layout_printf(C_RESET, C_RESET, C_RESET);
				node = node->next;
			}
			ft_lexerclear(&save, free);
			free(line);
		}
		else
			ft_exit_builtin(NULL);
	}
	return(0);
}
