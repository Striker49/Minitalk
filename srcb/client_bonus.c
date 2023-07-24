/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:18 by seroy             #+#    #+#             */
/*   Updated: 2023/07/24 16:33:44 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	if (sig == SIGUSR1)
		printf("Signal transmitted successfully\n");
}

void	uint2bin(unsigned long int len, int pid, siginfo_t *info)
{
	int	i;

	i = 31;
	while (i >= 0)
	{
		if ((len >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("Signal failed\n");
				exit(0);
			}
			usleep(100);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("Signal failed\n");
				exit(0);
			}
			usleep(100);
		}
		i--;
	}
}

void	char2bin(char c, int pid, siginfo_t *info)
{
	static int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("Signal failed\n");
				exit(0);
			}
			usleep(100);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("Signal failed\n");
				exit(0);
			}
			usleep(100);
		}
		i--;
	}
}

void	send_message(char *str, pid_t pid, siginfo_t *info)
{
	unsigned long int	len;
	int					j;

	len = ft_strlen(str) + 1;
	uint2bin(len, pid, info);
	j = 0;
	while (str[j])
	{
		char2bin(str[j], pid, info);
		j++;
	}
	char2bin('\n', pid, info);
	char2bin('\0', pid, info);
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	siginfo_t			info;
	int					pid;

	if (argc < 3)
	{
		printf("ERROR\nMissing arguments");
		exit (0);
	}
	if (argc > 3)
	{
		printf("ERROR\nToo many arguments");
		exit (0);
	}
	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid, &info);
	return (0);
}
