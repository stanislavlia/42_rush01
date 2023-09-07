/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neccesarry_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sliashko <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 10:59:42 by sliashko          #+#    #+#             */
/*   Updated: 2023/06/16 12:07:24 by sliashko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	is_digit(char c);
int	check_for_consev_space(char *inp);
int	check_for_content(char *str);
int	check_count_nums(char *input);

void	ft_putstr(char *str)
{
	int		i;
	char	c;

	i = 0;
	while (str[i] != '\0' )
	{
		c = str[i];
		write(1, &c, 1);
		i++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = n * -1;
	}
	if (n < 10)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

int	is_valid_input(char *input)
{	
	if (check_for_content(input) == 0)
	{
		return (0);
	}
	if (check_for_consev_space(input) == 0)
	{
		return (0);
	}
	if (check_count_nums(input) == 0)
	{
		return (0);
	}
	return (1);
}
