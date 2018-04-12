/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** returns a number, sent to the function as a string
*/

int my_get_nbr(char const *str, int *nbr)
{
	int i = 0;
	int sign = 1;

	if (str[0] == '-') {
		i++;
		sign = -1;
	}
	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			(*nbr) = (*nbr) * 10 + str[i] - 48;
		else {
			(*nbr) = 0;
			return (1);
		}
		i++;
	}
	(*nbr) = sign * (*nbr);
	return (0);
}
