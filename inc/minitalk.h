#ifndef MINITALK_H
# define MINITALK_H
# include "libft.h"
# include <unistd.h>
# include <stdio.h>
# include <signal.h>

typedef struct s_sigact
{
	int	spid;
	int	cpid;
}	t_sigact;

void	ft_free(unsigned char **str);
void	bitshift(unsigned char *str, int sig, int j);
void	ft_freeb(unsigned char **str);
void	bitshiftb(unsigned char *str, int sig, int j);


#endif