/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nguiard <nguiard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 07:16:16 by nguiard           #+#    #+#             */
/*   Updated: 2022/03/10 08:20:46 by nguiard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	catch_sigint(int sig, siginfo_t *truc, void *context);
void	catch_sigquit(int sig, siginfo_t *truc, void *context);
void	catch_sigstop(int sig, siginfo_t *truc, void *context);

void	catch_signals(void)
{
	struct sigaction sigint;
	struct sigaction sigquit;
	struct sigaction sigstop;

	sigint.sa_sigaction = catch_sigint;
	sigquit.sa_sigaction = catch_sigquit;
	sigstop.sa_sigaction = catch_sigstop;
	sigaction(SIGINT, &sigint, NULL);
	sigaction(SIGQUIT, &sigquit, NULL);
	sigaction(SIGSTOP, &sigstop, NULL);
}

void	catch_sigint(int sig, siginfo_t *truc, void *context)
{
	if (sig == SIGINT)
	{
		printf("Sigint catched\n");
		exit()
	}
}

void	catch_sigquit(int sig, siginfo_t *truc, void *context)
{
	if (sig == SIGQUIT)
	{
		printf("Sigquit catched\n");
	}
}

void	catch_sigstop(int sig, siginfo_t *truc, void *context)
{
	if (sig == SIGSTOP)
	{
		printf("Sigstop catched\n");
	}
}