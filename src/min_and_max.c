/*
** EPITECH PROJECT, 2018
** min_and_max.c
** File description:
** min_and_max.c
*/

#include <SFML/Graphics.h>

float min(float *list, int size)
{
	float temp = list[0];

	for (int i = 1; i != size; i++)
		if (temp > list[i])
			temp = list[i];
	return (temp);
}

float max(float *list, int size)
{
	float temp = list[0];

	for (int i = 1; i != size; i++)
		if (temp < list[i])
			temp = list[i];
	return (temp);
}

sfVector2f get_min_and_max(float *project, int nbr_point)
{
	sfVector2f minmax;
	minmax.x = min(project, nbr_point);
	minmax.y = max(project, nbr_point);
	return (minmax);
}
