/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_iuxx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:10:29 by aionescu          #+#    #+#             */
/*   Updated: 2021/09/28 18:42:12 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft_printf.h"

int	print_i(int num)
{
	char	*num_str;
	int		char_count;

	num_str = ft_itoa(num);
	char_count = ft_strlen(num_str);
	write(1, num_str, char_count);
	free(num_str);
	return (char_count);
}

int	print_u(unsigned int num)
{
	char	*num_str;
	int		char_count;

	num_str = ft_uitoa(num);
	char_count = ft_strlen(num_str);
	write(1, num_str, char_count);
	free(num_str);
	return (char_count);
}

int	print_x(unsigned int num, char x)
{
	int		char_count;
	char	*hex_str;
	int		index;

	hex_str = malloc(hex_size(num));
	hex_str = dec_to_hex(hex_str, num, hex_size(num), x);
	index = 0;
	char_count = 0;
	while (index < hex_size(num))
	{
		write(1, &hex_str[index], 1);
		char_count++;
		index++;
	}
	free(hex_str);
	return (char_count);
}
