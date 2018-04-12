/*
** EPITECH PROJECT, 2022
** my_radar_2017
** File description:
** Created by LEFEBVRE Jonathan
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "basic_sprite.h"
#include "lib/my/my.h"
#include "info.h"

void destruct_game_object(struct game_object **object)
{
	sfSprite_destroy((*object)->sprite);
	sfTexture_destroy((*object)->texture);
}
