/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:05:56 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 18:32:52 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		catch_sigquit(int sig, siginfo_t *truc, void *context);
static void	heredoc_sigint(int sig, siginfo_t *truc, void *context);

void	heredoc_sig(void)
{
	struct sigaction	sigint;

	sigint.sa_sigaction = heredoc_sigint;
	sigint.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, NULL, NULL);
}

static void	heredoc_sigint(int sig, siginfo_t *truc, void *context)
{
	(void)sig;
	(void)truc;
	(void)context;
	write(1, "\n", 1);
	set_ret_value(130);
	exit(130);
}
