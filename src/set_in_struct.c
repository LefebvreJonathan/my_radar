/*
** EPITECH PROJECT, 2017
** set_in_struct.c
** File description:
** 
*/

#include "info.h"
#include "lib/my/my.h"
#include <stdio.h>
#include <stdlib.h>

#define SIZE_A 7
#define SIZE_T 4
#define SIZE_D 2

int check_params(char **array, int size_max)
{
	int size = array_len(array);
	int number = 0;

	if ((array[0][0] == 'A' || array[0][0] == 'T') && size != size_max)
		return (84);
	else if (array[0][0] == 'D' && size < size_max)
		return (84);
	for (int i = 1; array[i] != NULL; i++) {
		if (my_get_nbr(array[i], &number) == 1)
			return (84);
	}
	return (0);
}

int check_array(char **array, info_s **info)
{
	char **temp = NULL;
	int error = 0;

	for (int i = 0; array[i] != NULL && error != 84; i++) {
		temp = str_to_word_array(array[i]);
		if (my_strcmp(temp[0], "A") == 0) {
			error = check_params(temp, SIZE_A);
			(*info)->nbr_a++;
		} else if (my_strcmp(temp[0], "T") == 0) {
			error = check_params(temp, SIZE_T);
			(*info)->nbr_t++;
		} else if (my_strcmp(temp[0], "D") == 0) {
			error = check_params(temp, SIZE_D);
			(*info)->nbr_d++;
		} else
			error = 84;
		free_array(temp);
	}
	return (error);
}

info_s *prepare_struct(char **array)
{
	info_s *info = malloc(sizeof(info_s));

	info->nbr_a = 0;
	info->nbr_t = 0;
	info->nbr_d = 0;
	if (check_array(array, &info) == 84) {
		free(info);
		return (NULL);
	}
	info->aircraft = malloc(sizeof(float *) * (info->nbr_a + 1));
	info->tower = malloc(sizeof(float *) * (info->nbr_t + 1));
	info->danger = malloc(sizeof(float *) * (info->nbr_d + 1));
	return (info);
}

float *set_params(char *str, int size)
{
	char **array = str_to_word_array(str);
	float *params = NULL;
	int nbr = 0;

	if (size == 0)
		size = array_len(array) - 1;
	params = malloc(sizeof(float) * (size + 1));
	for (int i = 0; array[i + 1] != NULL; i++) {
		my_get_nbr(array[i + 1], &nbr);
		params[i] = nbr;
		nbr = 0;
	}
	free_array(array);
	if (size == SIZE_A + 2) {
		params[SIZE_A - 1] = params[2] - params[0];
		params[SIZE_A] = params[3] - params[1];
	}
	return (params);
}

info_s *set_in_struct(char **array)
{
	info_s *info = prepare_struct(array);
	int nbr_a = 0;
	int nbr_t = 0;
	int nbr_d = 0;

	if (info == NULL)
		return (NULL);
	for (int i = 0; array[i] != NULL; i++) {
		if (array[i][0] == 'A') {
			info->aircraft[nbr_a++] = set_params(array[i],
				SIZE_A + 2);
			info->aircraft[nbr_a] = NULL;
		} else if (array[i][0] == 'T') {
			info->tower[nbr_t++] = set_params(array[i], SIZE_T);
			info->tower[nbr_t] = NULL;
		} else if (array[i][0] == 'D') {
			info->danger[nbr_d++] = set_params(array[i], 0);
			info->danger[nbr_d] = NULL;
		}
	}
	return (info);
}