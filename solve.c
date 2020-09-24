/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mashar <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:26:17 by mashar            #+#    #+#             */
/*   Updated: 2020/09/24 20:59:29 by mashar           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void		solve_two_degree(double *numbers, double **solution)
{
	double discriminant = (numbers[1] * numbers[1]) - 4 * numbers[0] * \
						  numbers[2];
	printf("Disc is %lf\n", discriminant);
	if (discriminant == 0)
	{
		solution[0][0] = 1;
		solution[0][1] = (-1 * numbers[1]) / (2 * numbers[2]);
		return ;
	}
	else if (discriminant < 0)
	{
		discriminant = discriminant * -1;
		solution[0][0] = -1;
		solution[0][1] = (-1 * numbers[1]) / (2 * numbers[2]);
		solution[0][2] = sqrt(discriminant) / (2 * numbers[2]);
		return ;
	}
	solution[0][0] = 2;
	solution[0][1] = (-1 * numbers[1] + sqrt(discriminant)) / (2 * numbers[2]);
	solution[0][2] = (-1 * numbers[1] - sqrt(discriminant)) / (2 * numbers[2]);
}

double		*solve(double *numbers, int degree)
{
	double	*solution;

	if (degree == 1)
	{
		solution = (double*)malloc(sizeof(double) * 2);
		if (!solution)
			return (NULL);
		solution[0] = 1;
		solution[1] = numbers[0] / numbers[1];
		//solve_one_degree(numbers, &solution);
		return (solution);
	}
	else
	{
		solution = (double*)malloc(sizeof(double) * 3);
		if (!solution)
			return (NULL);
		solve_two_degree(numbers, &solution);
		return (solution);
	}
}

int main()
{
	double numbers[5] = {4, 4, -9.3, 0, 0};
	double *solution;
	int degree = 2;
	solution = solve(numbers, degree);
	if(degree == 1)
		printf("Solution is %lf\n", solution[0]);
	else
	{
		if (solution[0] == 1)
			printf("Solution is %lf\n", solution[1]);
		else if (solution[0] == 2)
		{
			printf("Solution 1 is %lf\n", solution[1]);
			printf("Solution 2 is %lf\n", solution[2]);
		}
		else
			printf("The solution is a complex number: %lf + %lfi\n", solution[1], solution[2]);
	}
}
