/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

#include "info.h"
#include "lib/my/my.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

void free_tab_int(float **tab)
{
	for (int i = 0; tab[i] != NULL; i++)
		free(tab[i]);
	free(tab);
}

void free_struct(info_s *info)
{
	free_tab_int(info->aircraft);
	free_tab_int(info->tower);
	free_tab_int(info->danger);
	free(info);
}

int print_help()
{
	int fd = open("./README", O_RDONLY);
	char str[296];

	if (fd == -1) {
		write(1, "ERROR : Can't read\n", 19);
		return (1);
	}
	read(fd, str, 296);
	write(1, str, 296);
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	char **array = NULL;
	info_s *info = NULL;

	if (ac != 2)
		return (84);
	if (my_strcmp(av[1], "-h") == 0)
		return (print_help(av[0]));
	if ((array = set_file_to_array(av[1])) == NULL)
		return (84);
	if ((info = set_in_struct(array)) == NULL) {
		free_array(array);
		return (84);
	}
	radar(info);
	free_struct(info);
	free_array(array);
	return (0);
}
