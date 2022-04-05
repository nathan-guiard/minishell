/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 07:16:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/04/05 11:25:32 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	catch_sigint(int sig, siginfo_t *truc, void *context);
void	catch_sigquit(int sig, siginfo_t *truc, void *context);
void	catch_sigstop(int sig, siginfo_t *truc, void *context);

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

void	catch_sigint(int sig, siginfo_t *truc, void *context)
{
	char	*text;

	text = get_prompt_text();
	(void)sig;
	(void)truc;
	(void)context;
	printf("%s\n", text);
	rl_replace_line("", 0);
	free(text);
}

void	catch_sigquit(int sig, siginfo_t *truc, void *context)
{
	(void)sig;
	(void)truc;
	(void)context;
}
