/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:29:57 by aionescu          #+#    #+#             */
/*   Updated: 2021/09/22 22:03:28 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_ft_printf.h"

int	print_perc(void)
{
	write(1, "%", 1);
	return (1);
}

int	print_cspd(const char *str, va_list arguments, const int index)
{
	int	char_count_cspd;

	char_count_cspd = 0;
	if (str[index + 1] == 'c')
		char_count_cspd = print_c(va_arg(arguments, int));
	else if (str[index + 1] == 's')
		char_count_cspd = print_s(va_arg(arguments, char *));
	else if (str[index + 1] == 'p')
		char_count_cspd = print_p(va_arg(arguments, void *));
	else
		char_count_cspd = print_d(va_arg(arguments, int));
	return (char_count_cspd);
}

int	print_iuxx(const char *str, va_list arguments, const int index)
{
	int	char_count_iuxx;

	char_count_iuxx = 0;
	if (str[index + 1] == 'i')
		char_count_iuxx = print_i(va_arg(arguments, int));
	else if (str[index + 1] == 'u')
		char_count_iuxx = print_u(va_arg(arguments, unsigned int));
	else if (str[index + 1] == 'x')
		char_count_iuxx = print_x(va_arg(arguments, unsigned int), 'x');
	else
		char_count_iuxx = print_x(va_arg(arguments, unsigned int), 'X');
	return (char_count_iuxx);
}

int	print_element(const char *str, va_list arguments, int index)
{
	int	element_char_count;

	element_char_count = 0;
	if (str[index] == '%')
	{
		if (str[index + 1] == 'c' || str[index + 1] == 's'
			|| str[index + 1] == 'p' || str[index + 1] == 'd')
			element_char_count = print_cspd(str, arguments, index);
		else if (str[index + 1] == 'i' || str[index + 1] == 'u'
			|| str[index + 1] == 'x' || str[index + 1] == 'X')
			element_char_count = print_iuxx(str, arguments, index);
		else if (str[index + 1] == '%')
			element_char_count = print_perc();
	}
	else
	{
		write(1, &(str[index]), 1);
		element_char_count++;
	}
	return (element_char_count);
}

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	arguments;
	int		index;

	char_count = (-1);
	if (check_flags(str) == 1)
	{
		char_count = 0;
		va_start(arguments, str);
		index = 0;
		while (str[index] != '\0')
		{
			char_count = char_count + print_element(str, arguments, index);
			if (str[index] == '%')
				index = index + 2;
			else
				index++;
		}
		va_end(arguments);
	}
	return (char_count);
}
