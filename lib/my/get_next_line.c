/*
** EPITECH PROJECT, 2018
** GNL
** File description:
** GNL
*/

#include "lib/gnl/get_next_line.h"
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *my_strcat_gnl(char *dest, char const *src)
{
	int size_dest = 0;
	int n = 0;

	while (dest != NULL && dest[size_dest] != 0)
		size_dest++;
	for (n = 0; src[n] != 0; n++)
		dest[size_dest + n] = src[n];
	dest[size_dest + n] = 0;
	return (dest);
}

char *my_realloc(char *ptr, int size)
{
	int i = 0;
	int lenght = 0;
	char *str = NULL;

	if (ptr != NULL) {
		while (ptr[lenght] != 0)
			lenght++;
	}
	str = malloc(sizeof(char) * (lenght + size + 1));
	if (ptr != NULL) {
		while (ptr[i] != 0) {
			str[i] = ptr[i];
			i++;
		}
		str[i] = 0;
		free(ptr);
	}
	return (str);
}

int check_line(char *str, ssize_t size)
{
	int i = 0;

	if (size <= 0)
		return (0);
	while (str[i] != 0) {
		if (str[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

char *separe(char *extra, ssize_t size, int *end)
{
	char *str = NULL;
	int size_str = 0;
	int n = 0;

	while (extra[size_str] != '\n' && extra[size_str] != 0)
		size_str++;
	str = malloc(sizeof(char) * size_str + 1);
	for (n = 0; n < size_str; n++) {
		str[n] = extra[n];
		str[n + 1] = 0;
	}
	for (n = 0; extra[size_str + n + 1] != 0; n++) {
		extra[n] = extra[size_str + n + 1];
		extra[n + 1] = 0;
	}
	extra[n] = 0;
	if (size == 0 && extra[0] == 0) {
		free(extra);
		(*end) = 1;
	}
	return (str);
}

char *get_next_line(int fd)
{
	static char *extra = NULL;
	static int end = 0;
	char *str = NULL;
	char buf[READ_SIZE + 1];
	ssize_t size = 0;

	if (fd < 0 || end != 0)
		return (NULL);
	do {
		size = read(fd, &buf, READ_SIZE);
		buf[size] = 0;
		extra = my_realloc(extra, size + 1);
		extra = my_strcat_gnl(extra, buf);
	} while (check_line(extra, size) != 0);
	str = separe(extra, size, &end);
	return (str);
}
