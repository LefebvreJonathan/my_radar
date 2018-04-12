/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** function that concatenates two strings
*/

#include "lib/my/my.h"
#include <stdlib.h>
#include <string.h>

char *my_strcat(char *dest, char const *src)
{
        int i = my_strlen(dest);
        int j = 0;
        char *str = malloc(
                sizeof(char) * (my_strlen(dest) + my_strlen(src) + 1));

        str = my_strcpy(str, dest);
        while (src[j] != 0) {
                str[i + j] = src[j];
                str[i + j + 1] = 0;
                j++;
        }
        free(dest);
        dest = str;
        return (dest);
}
