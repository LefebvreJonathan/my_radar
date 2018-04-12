/*
** EPITECH PROJECT, 2018
** my_arrayintlen.c
** File description:
** calcul the lenght of an int array
*/

#include <stdlib.h>

int my_arrayintlen(int **av)
{
	int i = 0;

	while (av[i] != NULL)
		i++;
	return (i);
}
