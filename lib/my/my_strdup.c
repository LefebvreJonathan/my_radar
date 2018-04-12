/*
** EPITECH PROJECT, 2017
** my_strdup.c
** File description:
** function that allocates memory and copies the string given as argument in it
*/

#include "lib/my/my.h"
#include <stdlib.h>

char *my_strdup(char const *src)
{
	char *ptr = 0;
	int i = 0;

	ptr = malloc(sizeof(char) * (my_strlen(src) + 1));
	while (src[i] > i) {
                ptr[i] = src[i];
                i++;
        }
        ptr[i] = '\0';
	return(ptr);
}
