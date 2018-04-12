/*
** EPITECH PROJECT, 2022
** my_world_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include <stdlib.h>
#include <stdio.h>

void free_array(char **array)
{
	for (int n = 0; array[n] != NULL; n++)
		free(array[n]);
	free(array);
}