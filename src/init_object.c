/*
** EPITECH PROJECT, 2022
** my_radar_2017
** File description:
** Created by LEFEBVRE Jonathan
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

struct game_object *create_object(const char *path_to_spritesheet)
{
	struct game_object *temp = malloc(sizeof(struct game_object));

	temp->texture = sfTexture_createFromFile(path_to_spritesheet, NULL);
	if (temp->texture == NULL)
		return (NULL);
	temp->sprite = sfSprite_create();
	sfSprite_setTexture(temp->sprite, temp->texture, sfTrue);
	return (temp);
}

sfConvexShape *set_hitbox(void)
{
	sfVector2f point = {0, 0};
	sfVector2f origin = {10, 10};
	sfConvexShape *temp;

	temp = sfConvexShape_create();
	sfConvexShape_setPointCount(temp, 4);
	sfConvexShape_setPoint(temp, 0, point);
	point.x = 20;
	sfConvexShape_setPoint(temp, 1, point);
	point.y = 20;
	sfConvexShape_setPoint(temp, 2, point);
	point.x = 0;
	sfConvexShape_setPoint(temp, 3, point);
	sfConvexShape_setOrigin(temp, origin);
	return (temp);
}

game_s **init_object(void)
{
	game_s **temp = malloc(sizeof(game_s * ) * 5);
	temp[PLANE] = create_object("ressources/plane.png");
	temp[TOWER] = create_object("ressources/tower.png");
	temp[DANGER] = create_object("ressources/cloud.png");
	temp[MAP] = create_object("ressources/map.png");
	temp[PLANE]->hitbox = set_hitbox();
	temp[4] = NULL;
	return (temp);
}

sfMusic *load_music(void)
{
	sfMusic *music = sfMusic_createFromFile("ressources/music.ogg");

	sfMusic_setLoop(music, sfTrue);
	sfMusic_play(music);
	return (music);
}

void destroy_ressource(sfMusic *music, sfRenderWindow *window, game_s **object)
{
	sfMusic_destroy(music);
	sfRenderWindow_destroy(window);
	sfConvexShape_destroy(object[0]->hitbox);
	for (int i = 0; i != 4; i++) {
		sfTexture_destroy(object[i]->texture);
		sfSprite_destroy(object[i]->sprite);
		free(object[i]);
	}
	free(object);
}
