/*
** EPITECH PROJECT, 2022
** my_radar_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include "info.h"
#include "basic_sprite.h"
#include <SFML/Graphics.h>
#include <stdio.h>

void prepare_plane(struct game_object *aircraft, info_s *info, int i,
	sfVideoMode mode
)
{
	sfVector2f pos = {(0.0 + info->aircraft[i][0]) / 100.0 * mode.width,
		0.0 + info->aircraft[i][1] / 100.0 * mode.height};
	float angle = 0.0;

	sfSprite_setPosition(aircraft->sprite, pos);
	angle = calcul_angle(info->aircraft[i]);
	sfSprite_setRotation(aircraft->sprite, angle);
	sfConvexShape_setRotation(aircraft->hitbox, angle);
	info->aircraft[i][0] +=
		(0.0 + info->aircraft[i][6]) / (10000 / info->aircraft[i][4]);
	info->aircraft[i][1] +=
		(0.0 + info->aircraft[i][7]) / (10000 / info->aircraft[i][4]);
}

void print_plane(sfRenderWindow *window, struct game_object *aircraft, int *var)
{
	sfVector2f pos = sfSprite_getPosition(aircraft->sprite);

	if (var[HITBOX] == 1) {
		sfConvexShape_setPosition(aircraft->hitbox, pos);
		sfConvexShape_setFillColor(aircraft->hitbox, sfBlue);
		sfRenderWindow_drawConvexShape(window, aircraft->hitbox, NULL);
	}
	if (var[SPRITE] == 1) {
		sfRenderWindow_drawSprite(window, aircraft->sprite, NULL);
	}
}

int algo_collision(float **aircraft, struct game_object *game, int size,
	int pos, sfVideoMode mode
)
{
	sfVector2f pos1 = {(0.0 + aircraft[pos][0]) / 100.0 * mode.width,
		0.0 + aircraft[pos][1] / 100.0 * mode.height};
	sfVector2f pos2 = {0, 0};
	sfConvexShape *hitbox = set_hitbox();
	int collision = 0;

	sfConvexShape_setPosition(game->hitbox, pos1);
	for (int i = 0; i != size && collision == 0; i++)
		if (i != pos) {
			pos2.x = (0.0 + aircraft[i][0]) / 100.0 * mode.width;
			pos2.y = (0.0 + aircraft[i][1]) / 100.0 * mode.height;
			sfConvexShape_setPosition(hitbox, pos2);
			collision += SAT(game->hitbox, hitbox);
		}
	return (collision);
}

void position_plane(struct game_object *aircraft, info_s *info,
	sfRenderWindow *window, sfVideoMode mode, int *var
)
{
	sfVector2f pos = {0.3, 0.3};
	sfVector2f origin = {24, 64};

	sfSprite_setOrigin(aircraft->sprite, origin);
	sfSprite_setScale(aircraft->sprite, pos);
	for (int i = 0; i != info->nbr_a; i++) {
		if (info->aircraft[i][5] == 0 &&
			landing(info->aircraft[i]) == 0 &&
			algo_collision(info->aircraft, aircraft, info->nbr_a, i,
				mode) == 0) {
			prepare_plane(aircraft, info, i, mode);
			print_plane(window, aircraft, var);
		}
	}
}
