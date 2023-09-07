/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 13:20:50 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/17 13:20:54 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> //ONLY FOR DEBUG
#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);
int		check_entire_matrix(int matrix[4][4], int clues[16]);
int		is_valid_buildg(int matrix[4][4], int buildg, int x, int y);
void	print_matrix(int size, int matrix[4][4]);

int	solve(int matrix[4][4], int clues[16], int x, int y)
{
	int	val_to_try;

	val_to_try = 1;
	if (y == 4)
		return (check_entire_matrix(matrix, clues));
	if (x == 4)
		return (solve(matrix, clues, 0, y + 1));
	while (val_to_try <= 4)
	{	
		if (is_valid_buildg(matrix, val_to_try, x, y))
		{
			matrix[y][x] = val_to_try;
			if (solve(matrix, clues, x + 1, y))
				return (1);
			else
			{	
				matrix[y][x] = 0;
			}
		}
		val_to_try++;
	}
	return (0);
}
