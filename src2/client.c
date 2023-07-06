/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:18 by seroy             #+#    #+#             */
/*   Updated: 2023/07/06 16:50:42 by seroy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	sig_handler(char *str)
{
	int i;
	int j;
	char c;
	int bin;

	i = 7;
	j = 0;
	while (str[j])
	{
		c = str[j];
		while (i >= 0)
		{
			bin = (c >> i) & 1;
			printf("%d", bin);
			i--;
		}
		printf("\n");
		i = 7;
		j++;
	}
	return (bin);
}

int main(int argc, char **argv)
{
	struct sigaction sa;
	int	pid;
	int i;
	
	// sa.sa_sigaction = sig_handler;
	// sigemptyset (SIGINFO);
	sa.sa_flags = 0;
	if (argc < 2)
		printf("ERROR\nMissing arguments");
	if (argc > 3)
		printf("ERROR\nToo many arguments");
	pid = sig_handler(argv[2]);
    return (0);
}