/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:02:59 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/19 11:24:46 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// int	find_smallest_in_a(t_stack *A)
// {
// 	t_list	*tmp;
// 	int		min;
// 	int		pos;
// 	int		i;

// 	tmp = A->head;
// 	min = *(tmp->content);
// 	pos = 0;
// 	i = 0;
// 	while (tmp)
// 	{
// 		if (*(tmp->content) < min)
// 		{
// 			min = *(tmp->content);
// 			pos = i;
// 		}
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	return (pos);
// }

// void	sort_5(t_stack *A, t_stack *B)
// {
// 	int	pos;

// 	pos = find_smallest_in_a(A);
// 	push_the_smallest_to_b(A, B, pos);
// 	pos = find_smallest_in_a(A);
// 	push_the_smallest_to_b(A, B, pos);
// 	sort_3(A);
// 	pa(A, B);
// 	pa(A, B);
// }

// void	push_the_smallest_to_b(t_stack *A, t_stack *B, int pos)
// {
// 	int	size;
// 	int	r;

// 	size = stack_size(A);
// 	if (pos <= size / 2)
// 	{
// 		while (pos-- > 0)
// 			ra(A);
// 	}
// 	else
// 	{
// 		r = size - pos;
// 		while (r-- > 0)
// 			rra(A);
// 	}
// 	pb(A, B);
// }

void	full_exit(t_stack *stack)
{
	write(1, "Error!\n", 7);
	stack_clear(stack);
	exit(1);
}

int	is_valid_int(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if ((sign == 1 && result > 2147483647)
			|| (sign == -1 && result > 2147483648))
			return (0);
	}
	return (1);
}
