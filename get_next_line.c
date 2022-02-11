#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"
#include <fcntl.h>

int 	ft_strlen(char *str)
{
	int i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	char *str;
	int str_len = ft_strlen(s1) + ft_strlen(s2);
	int i = 0;
	int j = 0;


	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		*s1 = '\0';
	}
	if (!s1 || !s2)
	{
		free(s1);
		return (NULL);
	}
	str = malloc((sizeof(char) * (str_len + 1)));
	if (!str)
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[str_len] = '\0';
	free(s1);
	return (str);
}

int ft_strchr(char *str, char c)
{
	int i = 0;

	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *ft_get_line(char *save)
{
	char *str;
	int i = 0;


	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (NULL);
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		str[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		str[i] = save[i];
		i++;
	}
	str[i] = '\0';
	return (str);

}

char *ft_save(char *save)
{
	int i = 0;
	int k = 0;
	char *str;

	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	while (save[i] && save[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (ft_strlen(save) - i));
	if (!str)
		return NULL;
	i++;
	while (save[i] != '\0')
	{
		str[k] = save[i];
		k++;
		i++;
	}
	str[k] = '\0';
	free(save);
	return (str);
}

char *ft_read_and_save(int fd, char *save)
{
	char *buff;
	int n = 1;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n') && n != 0)
	{
		n = read(fd, buff, BUFFER_SIZE);
		if (n == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[n] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char *get_next_line(int fd)
{
	char *line;
	static char *save;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);

}

int main()
{
	int fd = open("42", O_RDONLY);
	char *str;

	str = get_next_line(fd);


	while (str)
	{
		printf("%s", str);
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (0);
}