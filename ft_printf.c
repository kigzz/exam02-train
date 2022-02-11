#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putstr(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	return (i);
}

int ft_strlen(char *str)
{
	if (!str)
		return (0);
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_putbase(long long int n, char *base)
{
	int minus;

	minus = 0;
	if (n < 0)
	{
		n = -n;
		minus = ft_putchar('-');
	}
	if (n >= ft_strlen(base))
	{
		ft_putbase(n / ft_strlen(base), base);
		minus += ft_putchar(base[n % ft_strlen(base)]);
	}
	else
		minus += ft_putchar(base[n]);
	return (minus);
}

int ft_parse(char c, va_list arg)
{
	int i = 0;

	if (c == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (c == 'd')
		i = ft_putbase(va_arg(arg, int), "0123456789");
	else if (c == 'x')
		i = ft_putbase(va_arg(arg, unsigned int), "0123456789abcdef");
	return (i);
}


int ft_printf(const char *str, ...)
{
	int i = 0;
	int to_return = 0;
	va_list arg;

	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%')
			to_return += ft_parse(str[++i], arg);
		else
			to_return += ft_putchar(str[i]);
		i++;
	}
	va_end(arg);
	return (to_return);
}

int main()
{
	int i = 	ft_printf("%s\n", "toto");
	int k = ft_printf("Magic %s is %d\n", "number", 42);
	int j = ft_printf("Hexadecimal for %d is %x\n", 42, 42);
	printf("i = %d\nk = %d\nj = %d\n", i, k, j);
	ft_printf("i = %d\nk = %d\nj = %d\n", i, k, j);
	return (0);
}