/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/24 16:40:16 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

unsigned char	*string(int sig, siginfo_t *info, unsigned char *str2)
{
	static int	i = 0;
	static int	j = 0;
	int			spid;

	if (spid != info->si_pid)
	{
		i = 0;
		j = 0;
	}
	bitshiftb(str2, sig, j);
	if (i == 8)
	{
		if (str2[j] == '\0')
		{
			printf("%s\n", str2);
			kill(info->si_pid, SIGUSR1);
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
	static unsigned char	*str = 0;
	static int				i = 0;
	int						j;
	unsigned long int		len;
	int						spid;

	if (info->si_pid != spid)
		i = (ft_freeb(&str), 0);
	if (!str)
	{
		str = ft_calloc(1 + 1, sizeof(*str));
		if (!str)
			return (ft_freeb(&str), 0);
		i = 0;
	}
	bitshiftb(str, sig, 0);
	if (i == 31)
	{
		len = str[0];
		ft_freeb(&str);
		return (len);
	}
	i++;
	spid = info->si_pid;
	return (0);
}

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	*str2 = 0;
	unsigned long int		len;
	int						spid;

	if (info->si_pid != spid)
		ft_freeb(&str2);
	if (!str2)
		len = findstrlen(sig, info);
	if (len != 0)
	{
		if (!str2)
		{
			str2 = ft_calloc(len + 1, sizeof(*str2));
			if (!str2)
				return (ft_freeb(&str2));
		}
	}
	if (str2 && len != 0)
	{
		string(sig, info, str2);
	}
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
