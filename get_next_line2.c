#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line2.h"
#include <unistd.h>

//char    *get_next_line(int fd)
//{
//	char    save[999999];
//	char    buff[BUFFER_SIZE];
//	char    *line;
//	int        i;
//
//	i = 0;
//	if (fd < 0 || BUFFER_SIZE <= 0)
//		return (NULL);
//	save[i] = '\0';
//	while (read(fd, buff, 1) == 1)
//	{
//		save[i] = buff[0];
//		save[i + 1] = '\0';
//		if (save[i] == '\n')
//			break ;
//		i++;
//	}
//	if (save[0] == '\0')
//		return (NULL);
//	line = malloc(i + 2);
//	i = 0;
//	while (save[i])
//	{
//		line[i] = save[i];
//		i++;
//	}
//	line[i] = '\0';
//	return (line);
//}


char *get_next_line(int fd) {
	char *line;
	char save[999999];
	char buff[BUFFER_SIZE];
	int i = 0;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save[i] = '\0';
	while (read(fd, buff, 1) == 1)
	{
		save[i] = buff[0];
		save[i + 1] = '\0';
		if (save[i] == '\n')
			break;
		i++;
	}
	if (save[0] == '\0')
		return (NULL);
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i])
	{
		line[i] = save[i];
		i++;
	}
	line[i] = '\0';
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
		i++;
	}
	return (0);
}

//int main()
//{
//	char *line;
//	line = get_next_line(0);
//	while (line != NULL)
//	{
//		printf("%s", line);
//		free (line);
//		line = get_next_line(0);
//	}
//	return (0);
//}