/*
** EPITECH PROJECT, 2018
** str_to_word_array.c
** File description:
** str to word array
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "lib/my/my.h"

int compt_word(char const **str)
{
	int nbr_word = 0;

	if ((*str)[0] != ' ' && (*str)[0] != '\t')
		nbr_word++;
	for (int i = 0; (*str)[i] != 0; i++)
		if (((*str)[i] == ' ' || (*str)[i] == '\t') &&
			((*str)[i] != ' ' || (*str)[i] != '\t'))
			nbr_word++;
	return (nbr_word);
}

int copy_word(char ***array, char const **str, int pos, int word)
{
	int end_word = pos;
	int size_word = 0;

	while ((*str)[end_word] != ' ' && (*str)[end_word] != '\t' &&
		(*str)[end_word] != 0)
		end_word++;
	size_word = end_word - pos;
	(*array)[word] = malloc(sizeof(char) * size_word + 1);

	for (int i = 0; i != size_word; i++)
		(*array)[word][i] = (*str)[i + pos];
	(*array)[word][size_word] = 0;
	return (size_word);
}

char **str_to_word_array(char const *str)
{
	char **array;
	int a = 0;
	int i = 0;

	array = malloc(sizeof(char *) * (compt_word(&str) + 1));
	while (i <= my_strlen(str)) {
		while ((str[i] == ' ' || str[i] == '\t') && str[i] != 0)
			i++;
		if (str[i] != 0) {
			i += copy_word(&array, &str, i, a);
			a++;
		}
		i++;
	}
	array[a] = NULL;
	return (array);
}
