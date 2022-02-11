#include <unistd.h>

void ft_putchar(char c)
{
	write(1, &c, 1);
}

int check(char *str, char c, int index)
{
	int k = 0;
	if (!str)
		return (0);
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
	int j;

	if (argc == 3)
	{
		while (argv[1][i])
		{
			j = 0;
			if (!check(argv[1], argv[1][i], i))
			{
				while (argv[2][j])
				{
					if (argv[1][i] == argv[2][j])
					{
						ft_putchar(argv[1][i]);
						break;
					}
					j++;
				}
			}
			i++;
		}
	}
	write(1, "\n", 1);
	return (0);
}
