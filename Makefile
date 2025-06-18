# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hporta-c <hporta-c@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/28 12:01:54 by hporta-c          #+#    #+#              #
#    Updated: 2025/06/18 16:21:29 by hporta-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
SRCS = main.c split_params.c split_prepare.c array_created_from_stack.c \
		stack_created.c simple_push_swap.c simple_push_swap_more.c utils_one.c \
		utils_two.c longest_increasing.c push_swap_prepare.c move_in_stacks.c \
		instructions_one.c instructions_two.c instructions_three.c \
		insert_position_found.c push_swap_back.c
OBJS = $(SRCS:.c=.o)
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
