#include <stdio.h>
#include <stdlib.h>

char	bin2char(char *str)
{
	int		base;
	int		i;
	char	c;

	base = 1;
	c = 0;
	i = 7;
	while (i >= 0)
	{
		if (str[i] == '1')
			c += base;
		base = base * 2;
		i--;
	}
	return (c);

}

char	bin2char(char *str)
{
	int		base;
	int		i;
	char	c;

	base = 1;
	c = 0;
	i = 7;
	while (i >= 0)
	{
		if (str[i] == '1')
			c += base;
		base = base * 2;
		i--;
	}
	return (c);
}

int	main(int argc, char **argv)
{
	char *str;
	int	i;

	str = calloc(argc, sizeof(char *));
	if (!str)
		return (0);	
	i = 1;
	while (argv[i])
	{
		str[i - 1] = bin2char(argv[i]);
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
}