/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cspd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:10:14 by aionescu          #+#    #+#             */
/*   Updated: 2021/09/22 22:05:35 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft_printf.h"

int	print_any(char *any)
{
	int	i;

	i = 0;
	while (any[i] != '\0')
	{
		write(1, &(any[i]), 1);
		i++;
	}
	return (i);
}

int	print_c(int char_as_int)
{
	unsigned char	int_as_char;

	int_as_char = (unsigned char)char_as_int;
	write(1, &int_as_char, 1);
	return (1);
}

int	print_s(const char *str)
{
	int	char_count;

	if (str != NULL)
	{
		char_count = 0;
		while (str[char_count] != '\0')
		{
			write(1, &(str[char_count]), 1);
			char_count++;
		}
	}
	else
		char_count = print_any("(null)");
	return (char_count);
}

int	print_p(void *ptr)
{
	int				char_count;
	unsigned long	ul_value;
	char			*hex_str;
	int				index;

	if (ptr != NULL)
	{
		ul_value = (unsigned long)ptr;
		hex_str = malloc(hex_size(ul_value));
		hex_str = dec_to_hex(hex_str, ul_value, hex_size(ul_value), 'x');
		index = 0;
		char_count = print_any("0x");
		while (index < hex_size(ul_value))
		{
			write(1, &hex_str[index], 1);
			char_count++;
			index++;
		}
		free(hex_str);
	}
	else
		char_count = print_any("0x0");
	return (char_count);
}

int	print_d(int num)
{
	char	*num_str;
	int		char_count;

	num_str = ft_itoa(num);
	char_count = ft_strlen(num_str);
	write(1, num_str, char_count);
	free(num_str);
	return (char_count);
}
