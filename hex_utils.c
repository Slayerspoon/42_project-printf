/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 00:57:23 by aionescu          #+#    #+#             */
/*   Updated: 2021/09/21 22:19:12 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft_printf.h"

char	dec_to_hex_figure(int number, char x)
{
	char	hex_figure;

	hex_figure = '0';
	if (0 <= number && number <= 9)
		hex_figure = '0' + number;
	else if (10 <= number && number <= 15)
	{
		if (x == 'x')
			hex_figure = 'a' + (number % 10);
		else
			hex_figure = 'A' + (number % 10);
	}
	return (hex_figure);
}

int	hex_size(unsigned long num)
{
	size_t	size;

	size = 0;
	if (num != 0)
	{
		while (num > 0)
		{
			num = num / 16;
			size++;
		}
	}
	else
		size = 1;
	return (size);
}

char	*dec_to_hex(char *hex_str, unsigned long num, size_t str_size, char x)
{
	char	c;
	int		index;

	index = str_size - 1;
	while (index >= 0)
	{
		c = dec_to_hex_figure(num % 16, x);
		hex_str[index] = c;
		num = num / 16;
		index--;
	}
	return (hex_str);
}
