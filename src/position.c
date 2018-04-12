/*
** EPITECH PROJECT, 2018
** position.c
** File description:
** position of all of sprite
*/

#include "info.h"
#include "basic_sprite.h"
#include <SFML/Graphics.h>
#include <stdio.h>
#include "lib/my/my.h"

void set_circle(sfVector2f pos, sfVector2f origin, float radius,
	sfRenderWindow *window
)
{
	sfCircleShape *circle = sfCircleShape_create();

	sfCircleShape_setRadius(circle, radius);
	sfCircleShape_setOrigin(circle, origin);
	sfCircleShape_setPosition(circle, pos);
	sfCircleShape_setOutlineThickness(circle, 4);
	sfCircleShape_setFillColor(circle, sfTransparent);
	sfCircleShape_setOutlineColor(circle, sfRed);
	sfRenderWindow_drawCircleShape(window, circle, NULL);
	sfCircleShape_destroy(circle);
}

void position_tower(struct game_object *tower, info_s *info,
	sfRenderWindow *window, sfVideoMode mode, int *var
)
{
	int radius = 0;
	sfVector2f pos = {0, 0};
	sfVector2f origin = {0, 0};
	sfVector2f origin_tower = {20, 60};

	for (int i = 0; i != info->nbr_t; i++) {
		pos.x = (0.0 + info->tower[i][0]) / 100.0 * mode.width;
		pos.y = (0.0 + info->tower[i][1]) / 100.0 * mode.height;
		origin.x = ((0.0 + info->tower[i][2]) / 100 * mode.height);
		origin.y = ((0.0 + info->tower[i][2]) / 100 * mode.height);
		sfSprite_setOrigin(tower->sprite, origin_tower);
		sfSprite_setPosition(tower->sprite, pos);
		radius = (0.0 + info->tower[i][2]) / 100.0 * mode.height;
		if (var[HITBOX] == 1)
			set_circle(pos, origin, radius, window);
		if (var[SPRITE] == 1)
			sfRenderWindow_drawSprite(window, tower->sprite, NULL);
	}
}

void print_danger(sfConvexShape *convex, struct game_object *danger,
	sfRenderWindow *window, int *var
)
{
	if (var[HITBOX] == 1) {
		sfConvexShape_setFillColor(convex, sfWhite);
		sfRenderWindow_drawConvexShape(window, convex, NULL);
	}
	if (var[SPRITE] == 1) {
		sfConvexShape_setFillColor(convex, sfWhite);
		sfConvexShape_setTexture(convex, danger->texture, sfTrue);
		sfRenderWindow_drawConvexShape(window, convex, NULL);
	}
}

void position_danger(struct game_object *danger, info_s *info,
	sfRenderWindow *window, sfVideoMode mode, int *var
)
{
	int nbr = 0;
	sfConvexShape *convex = sfConvexShape_create();
	sfVector2f pt = {0, 0};

	for (int i = 0; i != info->nbr_d; i++) {
		nbr = intlen(info->danger[i]);
		sfConvexShape_setPointCount(convex, nbr / 2);
		for (int a = 0; a < nbr; a++) {
			pt.x = (0.0 + info->danger[i][a++]) / 100 * mode.width;
			pt.y = (0.0 + info->danger[i][a]) / 100 * mode.height;
			sfConvexShape_setPoint(convex, a / 2, pt);
		}
		print_danger(convex, danger, window, var);
	}
	sfConvexShape_destroy(convex);
}
