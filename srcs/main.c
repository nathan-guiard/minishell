/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 11:28:51 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/22 15:19:56 by nguiard          ###   ########.fr       */
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
			//printf("%d\n", symbol_change(line, 0));
			node = full_symbol_table(line);
			t_lexer *save = node;
			while (node != NULL)
			{
				set_layout_printf(C_GREEN, C_RESET, C_BOLD);
				printf("Content:%s [len: %ld]\nsymbol:%d\n\n", node->content, ft_strlen(node->content), node->symbol);
				set_layout_printf(C_RESET, C_RESET, C_RESET);
				node = node->next;
			}
			ft_lexerclear(&save, free);
		}
		else
			break;
	}
	ft_exit_builtin(NULL);
	return(0);
}


//0x0000007ff3202c