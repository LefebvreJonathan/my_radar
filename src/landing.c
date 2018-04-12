/*
** EPITECH PROJECT, 2018
** landing.c
** File description:
** landing.c
*/

#include "../include/info.h"
#include "../include/basic_sprite.h"

int norting(float *coord, int xd, int xa, int xv)
{

	if (coord[xv] > 0) {
		if (coord[xd] <= coord[xa])
			return (0);
		else
			return (1);
	} else if (coord[xv] <= 0) {
		if (coord[xd] >= coord[xa])
			return (0);
		else
			return (1);
	}
	return (0);
}

int landing(float *coord)
{
	if (norting(coord, 0, 2, 6) == 0 && norting(coord, 1, 3, 7) == 0)
		return (0);
	else
		return (1);
}

void hour(info_s *info, sfClock *clock)
{
	for (int i = 0; i != info->nbr_a; i++)
		if (info->aircraft[i][5] > 0)
			info->aircraft[i][5] -= 1;
	sfClock_restart(clock);
}
