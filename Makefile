# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aionescu <aionescu@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/20 22:20:02 by aionescu          #+#    #+#              #
#    Updated: 2021/10/06 18:50:22 by aionescu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = error_check.c ft_printf.c ft_uitoa.c hex_utils.c print_cspd.c print_iuxx.c

all: $(NAME)

$(NAME): clean
	cd libft && $(MAKE) fclean
	cd libft && $(MAKE)
	mv ./libft/libft.a $(NAME)
	$(CC) -c -Wall -Wextra -Werror $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)
	rm -f *.o
	chmod 777 libftprintf.a

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
