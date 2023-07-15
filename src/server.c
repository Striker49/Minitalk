/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/15 15:42:21 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_free(unsigned char **str)
{
	free(*str);
	*str = NULL;
}

char	bin2char(unsigned char *str)
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
	static unsigned char	*str;
	static unsigned char	*str2;
	int 					i;
	int						j;
	unsigned int			c;
	unsigned int			len;
	
	if (!str)
	{
		str = calloc((8 + 1), sizeof(*str));
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
		c = bin2char(str);
		if (!str2)
		{
			len = c;
			// printf("len:%d\n", len);
			str2 = ft_calloc(len + 1, sizeof(*str2));
			j = 0;
		}
		// ft_putchar_fd(c, 1);
		str2[j] = c;
		j++;
		if (c == '\0')
		{
			printf("%s", str2);
			ft_free(&str2);
		}
		ft_free(&str);
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