# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sjdia <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/12/09 18:18:11 by sjdia             #+#    #+#              #
#    Updated: 2025/12/09 18:18:12 by sjdia            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFALGES = -Wall -Wextra -Werror

SRCS = push_swap.c parssing/push_swap_utils.c parssing/parssing.c \
		parssing/push_swap_utils_2.c opirations/swap.c opirations/push.c opirations/rotate.c \
		opirations/reverse.c

OBJS = $(SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJS) push_swap.h
	cc $(CFALGES) $(OBJS) -o push_swap

%.o: %.c push_swap.h
	cc $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus