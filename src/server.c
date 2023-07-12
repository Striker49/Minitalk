/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/12 18:03:43 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int 	base;
	static int 	i;
	int 		j;
	char 		c;
	static char bin;
	
	(void)*ucontext;
	if (sig == SIGUSR1)
		printf("good\n");

	// i = 7;
	// j = 0;
	// base = 1;
	// bin = 0;
	// while (i >= 0)
	// {
	// 	if (sig == SIGUSR1) 
	// 		bin += base;
	// 	base = base * 2;
	// 	i--;
	// }
	// printf("%d", bin);
	// i = 7;
	// j++;
	// return ;
}

int	main(void)
{
	struct 		sigaction sa;
	pid_t 		pid;
	siginfo_t 	siginfo;
	
	pid = getpid();
	printf("Server PID:%d\n", pid);
	
	sigemptyset (&sa.sa_mask);
	sa.sa_flags = SIGINFO;
	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		sleep(1);
	return (0);
}