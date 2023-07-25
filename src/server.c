/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/25 11:21:44 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*string(int sig, siginfo_t *info, unsigned char *str2)
{
	static int	i = 0;
	static int	j = 0;
	int			spid;

	if (spid != info->si_pid && info->si_pid != 0)
	{
		i = 0;
		j = 0;
	}
	bitshift(str2, sig, j);
	if (i == 8)
	{
		if (str2[j] == '\0')
		{
			printf("%s\n", str2);
			return (NULL);
		}
		i = 0;
		j++;
	}
	i++;
	spid = info->si_pid;
	return (0);
}

unsigned long int	findstrlen(int sig, siginfo_t *info)
{
	static int					i = 0;
	static unsigned long int	len = 0;
	int							spid;

	if (info->si_pid != spid && info->si_pid != 0)
	{
		i = 0;
		len = 0;
	}
	if (sig == SIGUSR1)
		len = (i << 1) | 1;
	else
		len = (i << 1) | 0;
	if (i == 31)
		return (len);
	i++;
	spid = info->si_pid;
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	*str2 = 0;
	unsigned long int		len;
	int						spid;

	if (info->si_pid != spid && info->si_pid != 0)
	{
		ft_free(&str2);
		len = 0;
	}
	if (!str2)
		len = findstrlen(sig, info);
	if (len != 0)
	{
		if (!str2)
		{
			str2 = ft_calloc(len + 1, sizeof(unsigned char));
			if (!str2)
				return (ft_free(&str2));
		}
	}
	if (str2 && len != 0)
		string(sig, info, str2);
	spid = info->si_pid;
}

int	main(void)
{
	struct sigaction		sa;
	pid_t					pid;
	siginfo_t				siginfo;

	ft_memset(&sa, 0, sizeof(struct sigaction));
	ft_memset(&siginfo, 0, sizeof(siginfo_t));
	pid = getpid();
	printf("Server PID:%d\n", pid);
	sigemptyset (&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
