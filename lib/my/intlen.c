/*
** EPITECH PROJECT, 2018
** inten.c
** File description:
** give the lenght of int[]
*/

#include <stdio.h>

int intlen(int *str)
{
	int i = 0;

	while (str[i] != NULL)
		i++;
	return (i);
}
