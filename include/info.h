/*
** EPITECH PROJECT, 2017
** info.h
** File description:
**
*/

#ifndef INFO_H_
#define INFO_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>

#include "basic_sprite.h"

#define SPRITE 0
#define HITBOX 1

typedef struct info {
	float **aircraft;
	float **tower;
	float **danger;
	int nbr_a;
	int nbr_t;
	int nbr_d;
} info_s;

info_s *set_in_struct(char **array);

int radar(info_s *info);

void hour(info_s *info, sfClock *clock);

void position_plane(struct game_object *aircraft, info_s *info,
	sfRenderWindow *window, sfVideoMode mode, int *var);

void position_tower(struct game_object *tower, info_s *info,
	sfRenderWindow *window, sfVideoMode mode, int *var);

void position_danger(struct game_object *danger, info_s *info,
	sfRenderWindow *window, sfVideoMode mode, int *var);

int landing(float *coord);

float calcul_angle(float *coord);

char **set_file_to_array(char *file);

struct game_object *create_object(const char *path_to_spritesheet);

sfConvexShape *set_hitbox(void);

game_s **init_object(void);

sfMusic *load_music(void);

void destroy_ressource(sfMusic *music, sfRenderWindow *window, game_s **object);

void print_var(int *var, sfRenderWindow *window);

sfBool SAT(sfConvexShape *shape1, sfConvexShape *shape2);

#endif //INFO_H_
