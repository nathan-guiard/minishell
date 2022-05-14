/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgeorgin <tgeorgin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 07:16:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/05/14 15:19:34 by tgeorgin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	catch_sigint(int sig, siginfo_t *truc, void *context);
static void	catch_sigquit(int sig, siginfo_t *truc, void *context);

void	restore_default_sig(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_handler = SIG_DFL;
	sigquit.sa_handler = SIG_DFL;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

void	catch_signals(void)
{
	struct sigaction	sigint;
	struct sigaction	sigquit;

	sigint.sa_sigaction = catch_sigint;
	sigint.sa_flags = SA_RESTART;
	sigquit.sa_sigaction = catch_sigquit;
	sigquit.sa_flags = SA_RESTART;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
}

static void	catch_sigint(int sig, siginfo_t *truc, void *context)
{
	(void)sig;
	(void)truc;
	(void)context;
	write(1, "\n", 1);
	rl_replace_line("", 1);
	rl_on_new_line();
	rl_redisplay();
	set_ret_value(130);
}

static void	catch_sigquit(int sig, siginfo_t *truc, void *context)
{
	(void)sig;
	(void)truc;
	(void)context;
	write(1, "\033[2K\r", 5);
	rl_on_new_line();
	rl_redisplay();
}

void	signals_heredoc(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, handle_heredoc);
}