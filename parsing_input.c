/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush-01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:27:25 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/16 14:34:28 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

void	ft_putstr(char *str);

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	check_for_consev_space(char *inp)
{
	int	i;

	i = 1;
	while (inp[i] != '\0')
	{
		if (inp[i - 1] == ' ' && inp[i] == ' ')
			return (0);
		i++;
	}
	return (1);
}

//Input contains only nums or spaces or quotes
int	check_for_content(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!((str[i] >= '1' && str[i] <= '4') || str[i] == ' '))
			if (str[i] != '\"')
				return (0);
		i++;
	}
	return (1);
}

int	check_count_nums(char *input)
{
	int	nums;

	nums = 0;
	while (*input != '\0')
	{
		if (is_digit(*input))
		{
			if (!(*input >= '1' && *input <= '4'))
			{
				ft_putstr("Clues must be in range from 1 to 4!\n");
				return (0);
			}
			nums++;
		}
		input++;
	}
	return (nums == 16);
}

// ARGUMENTS MATCHING TABLE (index - meaning)
// 	 0		 1 		2 		3 		4		5 		6		7		
// "col1up col2up col3up col4up col1down col2down col3down col4down
//		8		9		10		11		12			13		14			15
// row1left row2left row3left row4left row1right row2right row3right row4right"
void	parse_and_put_to_array(int *arr, char *str_args)
{
	int	val;
	int	i;

	i = 0;
	while (*str_args != '\0')
	{
		if (is_digit(*str_args))
		{
			val = *str_args - '0';
			arr[i] = val;
			i++;
		}
		str_args++;
	}
}
