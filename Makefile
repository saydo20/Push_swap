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

SRCS = push_swap.c utils/push_swap_utils.c parssing/parssing.c \
		utils/push_swap_utils_2.c opirations/swap.c opirations/push.c opirations/rotate.c \
		opirations/reverse.c utils/push_swap_utils_4.c utils/sort.c \
		utils/push_swap_utils_3.c

OBJS = $(SRCS:.c=.o)

bonus_SRCS = bonus/checker.c bonus/get_next_line.c bonus/get_next_line_utils.c \
				bonus/utils.c bonus/utils_2.c bonus/utils_3.c bonus/opirations_bonus/rotate_bonus.c \
				bonus/parssing_bonus.c bonus/opirations_bonus/push_bonus.c bonus/opirations_bonus/swap_bonus.c \
				bonus/opirations_bonus/reverse_bonus.c   

bonus_OBJS = $(bonus_SRCS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME) : $(OBJS) push_swap.h
	cc -fsanitize=address $(CFALGES) $(OBJS) -o push_swap

bonus: $(bonus_OBJS) push_swap.h
	cc  -fsanitize=address $(CFALGES) $(bonus_OBJS) -o checker

%.o: %.c push_swap.h
	cc  -fsanitize=address $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(bonus_OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f checker

re: fclean all

.PHONY: all clean fclean re bonus

# -fsanitize=address