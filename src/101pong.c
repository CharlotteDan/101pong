/*
** EPITECH PROJECT, 2017
** 101pong
** File description:
** maths
*/
#include "my.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>

int	my_error(char *str, int n)
{
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] < 48 || str[i] > 57)
			return(84);
		i++;
	}
	if (n < 0)
		return(84);
	return(0);
}

int	angle(position vector)
{
	float calc;
	calc = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	calc = vector.z/calc;
	if (calc < -1 || calc > 1)
		return(84);
	calc = asin(calc);
	calc = 180/M_PI*calc;
	if (calc <= 0)
		calc = calc * -1;
	if (calc == -0.00)
		calc = calc * -1;
	printf("%s", "The incidence angle is :\n");
	printf("%.2f%s\n", calc, " degrees");
	return(0);
}

int	pong_calc(char **av)
{
	position t1;
	position t2;
	position vector;
	position vectort;
	float length;
	int n = atoi(av[7]);

	if (my_error(av[7], n) == 84)
		return(84);

	t1.x = atof(av[1]);
	t1.y = atof(av[2]);
	t1.z = atof(av[3]);
	t2.x = atof(av[4]);
	t2.y = atof(av[5]);
	t2.z = atof(av[6]);

	vector.x = (t2.x) - (t1.x);
	vector.y = (t2.y) - (t1.y);
	vector.z = (t2.z) - (t1.z);

	length = sqrtf(powf(vector.x, 2) + powf(vector.y, 2) + powf(vector.z, 2));
	if (length == 0)
		return(84);
	printf("%s", "The speed vector coordinates are : \n");
	printf("%c%.2f%c%.2f%c%.2f%c\n", '(', vector.x, ';', vector.y, ';', vector.z, ')');
	vectort.x = (n * vector.x + t2.x);
	vectort.y = (n * vector.y + t2.y);
	vectort.z = (n * vector.z + t2.z);
	printf("%s%d%s", "At time t+", n, ", ball coordinates will be : \n");
	printf("%c%.2f%c%.2f%c%.2f%c\n", '(', vectort.x, ';', vectort.y, ';', vectort.z, ')');
	if (t2.z <= 0 && vector.z >= 0)
		angle(vector);
	else if (t2.z >= 0 && vector.z <= 0)
		angle(vector);
	else
		printf("%s\n", "The ball won't reach the bat.");
	return(0);
}

int	main(int ac, char **av)
{
	if (((ac >= 'a') && (ac <= 'z')) || ((ac >= 'A') && (ac <= 'Z')))
		return(84);
	if (ac != 8)
		return(84);
	if (ac == 7)
		return(84);
	else {
		pong_calc(av);
		return(0);
	}
}
