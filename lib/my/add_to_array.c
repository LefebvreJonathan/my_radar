/*
** EPITECH PROJECT, 2022
** CPE_lemin_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include <stdlib.h>
#include <stdio.h>
#include "lib/my/my.h"

char **add_to_array(char **array, char *str)
{
	int size = array_len(array);
	char **temp = malloc(sizeof(char *) * (size + 2));
	int n = 0;

	while (n != size) {
		temp[n] = my_strdup(array[n]);
		n++;
	}
	temp[n] = my_strdup(str);
	temp[n + 1] = 0;
	if (array != NULL)
		free_array(array);
	array = temp;
	return (array);
}