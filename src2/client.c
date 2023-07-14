/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:18 by seroy             #+#    #+#             */
/*   Updated: 2023/07/14 15:25:19 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

// void	send_message(char *str, pid_t pid, siginfo_t *info)
// {
// 	if (str[0] == 'a')
// 	{
// 		kill(pid, SIGUSR1);
// 		usleep(100);
// 	}	
// 	if (str[0] == 'b')
// 	{
// 		kill(pid, SIGUSR2);
// 		usleep(100);
// 	}
	
	
// }

void	send_message(char *str, pid_t pid, siginfo_t *info)
{
	static int i;
	static int j;
	static char c;

	j = 0;
	while (str[j])
	{
		i = 7;
		c = str[j];
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
		j++;
	}
}

int main(int argc, char **argv)
{
	struct sigaction	sa;
	siginfo_t			info;
	int					pid;

	if (argc < 2)
		printf("ERROR\nMissing arguments");
	if (argc > 3)
		printf("ERROR\nToo many arguments");
		
	pid = ft_atoi(argv[1]);
	send_message(argv[2], pid, &info);
    return (0);
}