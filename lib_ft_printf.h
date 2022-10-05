/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_ft_printf.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 22:18:47 by aionescu          #+#    #+#             */
/*   Updated: 2021/09/28 18:51:23 by aionescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_FT_PRINTF_H
# define LIB_FT_PRINTF_H "lib_ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include "./libft/libft.h"

int		ft_printf(const char *str, ...);
int		print_element(const char *str, va_list arguments, int index);
int		print_cspd(const char *str, va_list arguments, const int index);
int		print_iuxx(const char *str, va_list arguments, const int index);
int		print_perc(void);
int		print_c(int char_as_int);
int		print_s(const char *str);
int		print_p(void *ptr);
int		print_d(int num);
int		print_i(int num);
int		print_u(unsigned int num);
int		print_x(unsigned int num, char c);
char	dec_to_hex_figure(int number, char x);
int		hex_size(unsigned long num);
char	*dec_to_hex(char *hex_str, unsigned long num, size_t str_size, char x);
int		check_flags(const char *str);
char	*ft_uitoa(unsigned int n);
size_t	get_number_length_u(unsigned int num);
char	*handle_number_u(char *number, long long llint, size_t index);

#endif
