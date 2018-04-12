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

sfText *prepare_var(int *var)
{
	sfText *text = sfText_create();
	char *sprite = my_strdup("Sprite = ");
	char *hitbox = my_strdup("\nHitbox = ");

	if (var[SPRITE] == 1)
		sprite = my_strcat(sprite, "ENABLE");
	else
		sprite = my_strcat(sprite, "DISABLE");
	if (var[HITBOX] == 1)
		hitbox = my_strcat(hitbox, "ENABLE");
	else
		hitbox = my_strcat(hitbox, "DISABLE");
	sprite = my_strcat(sprite, hitbox);
	sfText_setString(text, sprite);
	free(sprite);
	free(hitbox);
	return (text);
}

void print_var(int *var, sfRenderWindow *window)
{
	sfText *text = prepare_var(var);
	sfFont *font = sfFont_createFromFile("ressources/arial.ttf");
	sfVector2f pos = {2, 640};

	sfText_setFont(text, font);
	sfText_setColor(text, sfWhite);
	sfText_setPosition(text, pos);
	sfRenderWindow_drawText(window, text, NULL);
	sfText_destroy(text);
	sfFont_destroy(font);
}