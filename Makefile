# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 12:02:19 by atenhune          #+#    #+#              #
#    Updated: 2022/04/28 11:41:49 by atenhune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

INCLUDES = includes/

LIBFT = ./libft/libft.a

SRC = push_swap.c operations.c operations_2.c utils.c algorithms.c



all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -O3 -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIBFT) -I $(INCLUDES) 

clean :
	@rm -f ./libft/libft.a

fclean : clean
	@rm -f push_swap

re : fclean all
	
