/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver_alg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 11:19:43 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/17 11:19:44 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// ARGUMENTS MATCHING TABLE (index - meaning)
// 	 0		 1 		2 		3 		4		5 		6		7		
// "col1up col2up col3up col4up col1down col2down col3down col4down
//		8		9		10		11		12			13		14			15
// row1left row2left row3left row4left row1right row2right row3right row4right"
void	ft_putstr(char *str);

// direction in vertical: UP-DOWN
int	check_ver_down(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 0;
	max = 0;
	c_changes = 0;
	while (i < 4)
	{
		if (matrix[i][clue_ind] > max)
		{	
			c_changes++;
			max = matrix[i][clue_ind];
		}
		i++;
	}
	return (c_changes == clues[clue_ind]);
}

// direction in vertical: DOWN-UP
int	check_ver_up(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 3;
	max = 0;
	c_changes = 0;
	while (i > -1)
	{
		if (matrix[i][clue_ind - 4] > max)
		{	
			c_changes++;
			max = matrix[i][clue_ind - 4];
		}
		i--;
	}
	max = 0;
	return (c_changes == clues[clue_ind]);
}

//direction in horizontal
int	check_hor_right(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 0;
	max = 0;
	c_changes = 0;
	while (i < 4)
	{
		if (matrix[clue_ind - 8][i] > max)
		{	
			max = matrix[clue_ind - 8][i];
			c_changes++;
		}
		i++;
	}
	return (c_changes == clues[clue_ind]);
}

//direction in horizontal
int	check_hor_left(int matrix[4][4], int clues[16], int clue_ind)
{
	int	i;
	int	c_changes;
	int	max;

	i = 3;
	max = 0;
	c_changes = 0;
	while (i > -1)
	{
		if (matrix[clue_ind - 12][i] > max)
		{
			max = matrix[clue_ind - 12][i];
			c_changes++;
		}
		i--;
	}
	return (c_changes == clues[clue_ind]);
}

int	check_entire_matrix(int matrix[4][4], int clues[16])
{
	int	i;

	i = 0;
	while (i <= 15)
	{	
		if (i >= 0 && i <= 3 && !(check_ver_down(matrix, clues, i)))
		{
			return (0);
		}
		if (i >= 4 && i <= 7 && !(check_ver_up(matrix, clues, i)))
		{
			return (0);
		}
		if (i >= 8 && i <= 11 && !(check_hor_right(matrix, clues, i)))
		{	
			return (0);
		}
		if (i >= 12 && i <= 15 && !(check_hor_left(matrix, clues, i)))
		{
			return (0);
		}
		i++;
	}
	return (1);
}
