# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/23 13:23:32 by atenhune          #+#    #+#              #
#    Updated: 2022/04/25 15:07:14 by atenhune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDES = ./includes/

SRC = ft_memset.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strstr.c \
	ft_strnstr.c \
	ft_strcmp.c \
	ft_strncmp.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c  \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstiter.c \
	ft_lstadd.c \
	ft_lstmap.c \
	better_ft_itoa.c \
	better_ft_strnew.c \
	catchers.c \
	converters.c \
	flag_treatment.c \
	flag_treatment_2.c \
	flag_treatment_3.c \
	flag_treatment_4.c \
	flag_treatment_5.c \
	float_2.c \
	float_utils.c \
	float.c \
	format_reader.c \
	ft_printf.c \
	print_putnbr.c \
	printer_utils.c \
	printers_2.c \
	printers.c \
	specifiers.c \
	wildcard.c \
	
all : $(NAME)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(INCLUDES)
	@ar rc $(NAME) $(patsubst %.c,%.o,$(SRC)) 

clean :
	rm -f *.o

fclean : clean
	rm -f libft.a

re : fclean all