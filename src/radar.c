/*
** EPITECH PROJECT, 2017
** radar.c
** File description:
** 
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "basic_sprite.h"
#include "lib/my/my.h"
#include "info.h"

float calcul_angle(float *coord)
{
	sfVector2f origin = {1, 0};
	float a = coord[6] * origin.x + coord[7] * origin.y;
	float b = sqrt(pow(coord[6], 2) + pow(coord[7], 2)) *
		sqrt(pow(origin.x, 2) + pow(origin.y, 2));;
	float angle = a / b;
	angle = acos(angle);
	angle = angle * 180 / M_PI;
	if (coord[7] < 0)
		angle = angle * -1;
	return (angle);
}

void print_sprite(game_s **object, sfVideoMode mode, info_s *info,
	sfRenderWindow *window, int *var
)
{
	sfRenderWindow_clear(window, sfBlue);
	sfRenderWindow_drawSprite(window, object[MAP]->sprite, NULL);
	position_tower(object[TOWER], info, window, mode, var);
	position_danger(object[DANGER], info, window, mode, var);
	position_plane(object[PLANE], info, window, mode, var);
	print_var(var, window);
	sfRenderWindow_display(window);
}

int *close_window(sfRenderWindow *window, int *var)
{
	sfEvent event;

	while (sfRenderWindow_pollEvent(window, &event))
		if (event.type == sfEvtClosed || event.key.code == sfKeyEscape)
			sfRenderWindow_close(window);
	if (event.key.code == sfKeyL)
		var[HITBOX] *= -1;
	else if (event.key.code == sfKeyS)
		var[SPRITE] *= -1;
	return (var);
}

int *init_var(void)
{
	int *var = malloc(sizeof(int) * 2);

	var[SPRITE] = 1;
	var[HITBOX] = 1;
	return (var);
}

int radar(info_s *info)
{
	sfVideoMode mode = {1280, 720, 32};
	sfRenderWindow *window = sfRenderWindow_create(mode, "My_Radar",
		sfResize | sfClose, NULL);
	sfClock *clock = sfClock_create();
	sfMusic *music = load_music();
	game_s **object = init_object();
	sfTime time = sfClock_getElapsedTime(clock);
	int *var = init_var();

	if (!window || object == NULL)
		return (84);
	while (sfRenderWindow_isOpen(window)) {
		var = close_window(window, var);
		time = sfClock_getElapsedTime(clock);
		if (time.microseconds / 1000000.0 > 1)
			hour(info, clock);
		print_sprite(object, mode, info, window, var);
	}
	destroy_ressource(music, window, object);
	return (0);
}
