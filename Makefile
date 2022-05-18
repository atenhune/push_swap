# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 12:02:19 by atenhune          #+#    #+#              #
#    Updated: 2022/05/18 17:19:42 by atenhune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_2 = checker

INCLUDES = includes/

LIBFT = ./libft/libft.a

SRC_PATH = ./srcs/

SRC = push_swap.c operations.c operations_2.c utils.c printter.c \
	no_overflow_atoi.c five_sort.c four_sort.c operations_3.c three_sort.c \
	apply_large_sort.c large_utils.c large_sort.c utils_2.c utils_3.c \

SRC_2 = checker.c utils.c operations.c operations_2.c no_overflow_atoi.c \
	operations_3.c utils_3.c

all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -Wall -Wextra -Werror -o $(NAME) $(patsubst %,$(SRC_PATH)%,$(SRC)) $(LIBFT) -I $(INCLUDES)
	@gcc -Wall -Wextra -Werror -o $(NAME_2) $(patsubst %,$(SRC_PATH)%,$(SRC_2)) $(LIBFT) -I $(INCLUDES)

clean :
	@rm -f ./libft/libft.a
	@rm -f ./libft/*.o

fclean : clean
	@rm -f push_swap
	@rm -f checker

re : fclean all
	
