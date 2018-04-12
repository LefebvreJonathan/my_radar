/*
** EPITECH PROJECT, 2017
** set_array.c
** File description:
** 
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "info.h"
#include "lib/my/my.h"

char **set_file_to_array(char *file)
{
	int fd = open(file, O_RDONLY);
	char *str = NULL;
	char **array = NULL;

	if (fd == -1)
		return (NULL);
	array = malloc(sizeof(char *));
	array[0] = NULL;
	str = get_next_line(fd);
	for (int i = 0; str != NULL; i++) {
		array = add_to_array(array, str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (array);
}

