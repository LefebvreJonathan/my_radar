/*
** EPITECH PROJECT, 2018
** array_len.c
** File description:
** array_len
*/

#include <stdio.h>

int array_len(char **array)
{
	int size = 0;

	while (array[size] != NULL)
		size++;
	return (size);
}
