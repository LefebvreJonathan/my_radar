/*
** EPITECH PROJECT, 2017
** my_strcmp.c
** File description:
** strcmp function
*/

#include <stdio.h>
#include "lib/my/my.h"

int my_strcmp(char const *s1, char const *s2)
{
	int i = 0;
	int calcul = 0;

	if (s1 == NULL || s2 == NULL || my_strlen(s1) != my_strlen(s2))
		return (1);
	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
		if (s1[i] != s2[i]) {
			calcul = s1[i] - s2[i];
			return (calcul);
		}
	return (0);
}
