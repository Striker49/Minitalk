/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/20 14:35:02 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free(unsigned char **str)
{
	if (str)
	{
		free(*str);
		*str = NULL;
	}
}


void	bitshift(unsigned char *str, int sig, int j)
{
	if (sig == SIGUSR1)
		str[j] = (str[j] << 1) | 1;
	else
		str[j] = (str[j] << 1) | 0;
}

// void	_print(unsigned long int i, unsigned long int j, int sig, siginfo_t *info, unsigned char **str, unsigned char **str2)
// {

// }

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	static unsigned char	*str = 0;
	static unsigned char	*str2 = 0;
	unsigned long int 		i;
	int						j;
	unsigned long int		len;
	int 					spid;
	
	if (info->si_pid != spid)
	{
		ft_free(&str);
		ft_free(&str2);
	}
	if(!str)
	{
		str = ft_calloc(1 + 1, sizeof(*str));
		if (!str)
			return(ft_free(&str));
		i = 0;
		j = 0;
	}
	if (!str2)
		bitshift(str, sig, j);
	if (str2)
	{
		bitshift(str2, sig, j);
		if (i == 8)
		{
			if (str2[j] == '\0')
			{
				printf("%s\n", str2);
				kill(info->si_pid, SIGUSR1);
				ft_free(&str2);
				ft_free(&str);
				return ;
			}
			i = 0;
			j++;
		}
	}
	if (i == 31)
	{
		len = str[0];
		str2 = ft_calloc(len + 1, sizeof(*str2));
		if (!str2)
			return(ft_free(&str2));
		i = 0;
	}
	i++;
	spid = info->si_pid;
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
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &sig_handler;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}