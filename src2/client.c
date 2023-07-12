/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:18 by seroy             #+#    #+#             */
/*   Updated: 2023/07/12 18:07:39 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_message(char *str, pid_t pid, siginfo_t *info)
{
	static int i;
	static int j;
	static char c;

	kill(pid, SIGUSR1);
	usleep(100);

	// j = 0;
	// while (str[j])
	// {
	// 	i = 7;
	// 	c = str[j];
	// 	while (i >= 0)
	// 	{
	// 		if ((c >> i) & 1)
	// 		{
	// 			kill(pid, SIGUSR1);
	// 			usleep(100);
	// 		}
	// 		else
	// 		{
	// 			kill(pid, SIGUSR2);
	// 			usleep(100);				
	// 		}
	// 		i--;
	// 	}
	// 	j++;
	// }
	return ;
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