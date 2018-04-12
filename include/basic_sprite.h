/*
** EPITECH PROJECT, 2017
** basic_sprite.c
** File description:
** 
*/

#ifndef BASIC_SPRITE_H_
#define BASIC_SPRITE_H_

#include <SFML/Graphics/Shape.h>

#define PLANE 0
#define TOWER 1
#define DANGER 2
#define MAP 3


typedef struct game_object {
	sfSprite *sprite;
	sfTexture *texture;
	sfConvexShape *hitbox;
} game_s;

#endif //BASIC_SPRITE_H_
