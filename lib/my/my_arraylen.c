/*
** EPITECH PROJECT, 2018
** my_arraylen.c
** File description:
** calcul the lenght of an array
*/

#include <stdlib.h>

int my_arraylen(char **av)
{
	int i = 0;

	while (av[i] != NULL)
		i++;
	return (i);
}
