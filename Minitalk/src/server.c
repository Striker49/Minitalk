/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/14 16:01:57 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free(char *str)
{
	free(str);
	str = NULL;
}

// void	sig_handler(int sig, siginfo_t *info, void *ucontext)
// {	
// 	(void)*ucontext;
	
// 	if (sig == SIGUSR1)
// 		printf("Good\n");	
// 	if (sig == SIGUSR2)
// 		printf("Bad\n");
// 	// ft_memset(&info, 0, sizeof(siginfo_t));
// }

char	bin2char(char *str)
{
	int	bin;
	int	base;
	int	i;
	int	j;
	
	i = 8;
	j = 0;
	base = 1;
	bin = 0;
	// printf("%d\n", i);
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		if (str[i] == '1') 
			bin += base;
		base = base * 2;
		// printf("char%d:%c\n", i, str[i]);
		i--;
	}
	return (bin);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static int 	base;
	int 	i;
	// static int 	j;
	static char	*str;
	static char bin;
	char		c;
	
	// printf("%d\n", i);
	if (!str)
	{
		str = calloc(9, sizeof(*str));
		i = 0;
	}
	if (sig == SIGUSR1)
		str[i] = '1';
	else if (sig == SIGUSR2)
		str[i] = '0';
	i++;
	if (i == 8)
	{
		str[i] = '\0';
		i = 0;
		c = bin2char(str);
		printf("c:%c\n", c);
		// free(str);
	}
}


int	main(void)
{
	struct 		sigaction sa;
	pid_t 		pid;
	siginfo_t 	siginfo;
	
	ft_memset(&sa, 0, sizeof(struct sigaction));
	ft_memset(&siginfo, 0, sizeof(siginfo_t));
	pid = getpid();
	printf("Server PID:%d\n", pid);
	
	sigemptyset (&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);

	while (1)
		sleep(1);
	return (0);
}