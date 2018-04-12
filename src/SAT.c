/*
** EPITECH PROJECT, 2018
** colision.c
** File description:
** 
*/

#include <SFML/Graphics.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <math.h>

sfVector2f get_min_and_max(float *project, int nbr_point);

float prod_scal(sfVector2f vector_a, sfVector2f vector_b)
{
	return (vector_a.x * vector_b.x + vector_a.y * vector_b.y);
}

int set_normal(sfConvexShape *shape, sfVector2f *normal, int i)
{
	sfVector2f pos = {sfConvexShape_getPosition(shape).x,
		sfConvexShape_getPosition(shape).y};

	while (i < (int)sfConvexShape_getPointCount(shape)) {
		normal[i].x = (sfConvexShape_getPoint(shape, i + 1).x + pos.x) -
			(sfConvexShape_getPoint(shape, i).x + pos.x);
		normal[i].y = (sfConvexShape_getPoint(shape, i + 1).y + pos.y) -
			(sfConvexShape_getPoint(shape, i).y + pos.y);
		i++;
	}
	normal[i].x = sfConvexShape_getPoint(shape, 0).x + pos.x -
		sfConvexShape_getPoint(shape, i).x + pos.x;
	normal[i].y = sfConvexShape_getPoint(shape, 0).y + pos.y -
		sfConvexShape_getPoint(shape, i).y + pos.y;
	i++;
	return (i);
}

sfVector2f *get_normal(sfConvexShape *shape1, sfConvexShape *shape2)
{

	int i = 0;
	sfVector2f *normal = malloc(sizeof(sfVector2f) *
		(sfConvexShape_getPointCount(shape1) +
			sfConvexShape_getPointCount(shape2)));

	i += set_normal(shape1, normal, i);
	i += set_normal(shape2, normal, i);
	return (normal);
}

void get_project(sfConvexShape *shape, float *project, int n, sfVector2f *normal
)
{
	sfVector2f temp = {0, 0};

	for (int i = 0; i < (int)sfConvexShape_getPointCount(shape); i++) {
		temp.x = sfConvexShape_getPoint(shape, i).x +
			sfConvexShape_getPosition(shape).x;
		temp.y = sfConvexShape_getPoint(shape, i).y +
			sfConvexShape_getPosition(shape).y;
		project[i] = prod_scal(temp, normal[n]);
	}
}

sfBool SAT(sfConvexShape *shape1, sfConvexShape *shape2)
{
	sfVector2f *normal = get_normal(shape1, shape2);
	int size_a = sfConvexShape_getPointCount(shape1);
	int size_b = sfConvexShape_getPointCount(shape2);
	float *project_a = malloc(sizeof(float) * size_a);
	float *project_b = malloc(sizeof(float) * size_b);
	sfVector2f minmax_point_a = {0, 0};
	sfVector2f minmax_point_b = {0, 0};

	for (int n = 0; n < size_a + size_b; n++) {
		get_project(shape1, project_a, n, normal);
		get_project(shape2, project_b, n, normal);
		minmax_point_a = get_min_and_max(project_a, size_a);
		minmax_point_b = get_min_and_max(project_b, size_b);
		if (minmax_point_a.y < minmax_point_b.x ||
			minmax_point_b.y < minmax_point_a.x)
			return (sfFalse);
	}
	return (sfTrue);
}
