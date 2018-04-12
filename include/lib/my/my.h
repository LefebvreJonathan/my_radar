/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_Y_

char **add_to_array(char **array, char *str);

int array_len(char **array);

void free_array(char **array);

int my_arrayintlen(int **av);

int my_arraylen(char **av);

int my_get_nbr(char const *str, int *nbr);

char *my_strcat(char *dest, char const *src);

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src);

char *get_next_line(int fd);

char **str_to_word_array(char const *str);

int my_strcmp(char const *s1, char const *s2);

char **add_to_array(char **array, char *str);

int intlen(float *str);

#endif //MY_H_
