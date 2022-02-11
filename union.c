#include <stdio.h>
#include <unistd.h>

int 	ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int check(char *str, char c, int index)
{
	int k = 0;

	while (k < index)
	{
		if (str[k] == c)
			return (1);
		k++;
	}
	return (0);
}

int main(int argc, char **argv)
{
	int i = 0;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			if (check(argv[1], argv[1][i], i) == 0)
				ft_putchar(argv[1][i]);
			i++;
		}
		i = 0;
		while (argv[2][i])
		{
			if (check(argv[2], argv[2][i], i) == 0 &&
				check(argv[1], argv[2][i], ft_strlen(argv[1])) == 0)
				ft_putchar(argv[2][i]);
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}