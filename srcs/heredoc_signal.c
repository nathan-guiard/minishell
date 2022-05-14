/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_signal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 15:05:56 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 16:20:53 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		catch_sigquit(int sig, siginfo_t *truc, void *context);
static void	heredoc_sigint(int sig, siginfo_t *truc, void *context);

void	heredoc_sig(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_sigaction = heredoc_sigint;
	sigint.sa_flags = SA_RESTART;
	sigquit.sa_sigaction = catch_sigquit;
	sigquit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

static void	heredoc_sigint(int sig, siginfo_t *truc, void *context)
{
	(void)sig;
	(void)truc;
	(void)context;
	set_ret_value(130);
	exit(130);
}
