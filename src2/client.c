/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:18 by seroy             #+#    #+#             */
/*   Updated: 2023/07/15 16:04:49 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	char2bin(unsigned int i, int pid, siginfo_t *info)
// {
// 	int	alex;

// 	alex = 31;
// 	while (alex >= 0)
// 	{
// 		if ((i >> alex) & 1)
// 		{
// 			if (kill(pid, SIGUSR1) == -1)
// 				ft_putchar_fd('1', 1);
// 			usleep(100);
// 		}
// 		else
// 		{
// 			if (kill(pid, SIGUSR2) == -1)
// 				ft_putchar_fd('0', 1);
// 			usleep(100);				
// 		}
// 		alex--;
// 	}
// }


void	char2bin(char c, int pid, siginfo_t *info)
{
	static int	i;

	i = 7;
	while (i >= 0)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				printf("Signal failed\n");
			usleep(100);
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				printf("Signal failed\n");
			usleep(100);				
		}
		i--;
	}
}

void	send_message(char *str, pid_t pid, siginfo_t *info)
{
	int j;
	int len;
	
	len = ft_strlen(str);
	char2bin(len, pid, info);
	j = 0;
	while (str[j])
	{
		char2bin(str[j], pid, info);
		j++;
	}
	char2bin('\n', pid, info);
	char2bin('\0', pid, info);
}

int main(int argc, char **argv)
{
	struct sigaction	sa;
	siginfo_t			info;
	int					pid;

	if (argc < 3)
		printf("ERROR\nMissing arguments");
	if (argc > 3)
		printf("ERROR\nToo many arguments");
		
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid, &info);
    return (0);
}