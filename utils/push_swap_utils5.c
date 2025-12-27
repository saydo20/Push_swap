/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 11:12:06 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/27 12:34:57 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_pos(t_stack *stack, int number)
{
	t_list	*tmp;
	int		pos;

	pos = 0;
	tmp = stack->head;
	while (tmp)
	{
		if (*(tmp->content) == number)
			break ;
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	find_second_max(t_stack *B, int max)
{
	t_list	*tmp;
	int		second;
	int		found;

	tmp = B->head;
	second = 0;
	while (tmp)
	{
		if (*tmp->content != max)
		{
			if (*tmp->content > second)
				second = *tmp->content;
		}
		tmp = tmp->next;
	}
	return (second);
}

void	rotate_to_top(t_stack *B, int value)
{
	int	pos;

	pos = find_pos(B, value);
	while (*B->head->content != value)
	{
		if (pos <= B->size / 2)
			rb(B);
		else
			rrb(B);
	}
}
