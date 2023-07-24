/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seroy <seroy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 14:31:23 by seroy             #+#    #+#             */
/*   Updated: 2023/07/24 16:30:55 by seroy            ###   ########.fr       */
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
