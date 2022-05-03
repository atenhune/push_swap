# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atenhune <atenhune@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/20 12:02:19 by atenhune          #+#    #+#              #
#    Updated: 2022/05/03 15:17:45 by atenhune         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_2 = checker

INCLUDES = includes/

LIBFT = ./libft/libft.a

SRC = push_swap.c operations.c operations_2.c utils.c algorithms.c

SRC_2 = checker.c utils.c operations.c operations_2.c


all : $(NAME)

$(NAME):
	@make -C libft/
	@gcc -O3 -Wall -Wextra -Werror -o $(NAME) $(SRC) $(LIBFT) -I $(INCLUDES)
	@gcc -O3 -Wall -Wextra -Werror -o $(NAME_2) $(SRC_2) $(LIBFT) -I $(INCLUDES) 

clean :
	@rm -f ./libft/libft.a
	@rm -f ./libft/*.o

fclean : clean
	@rm -f push_swap
	@rm -f checker

re : fclean all
	
