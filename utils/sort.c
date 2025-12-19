/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:43:03 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/19 11:27:53 by sjdia            ###   ########.fr       */
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

void	push_back_to_a(t_stack *A, t_stack *B)
{
	int		max;
	int		pos;

	while (B->head)
	{
		max = find_max(B);
		pos = find_pos_max(B);
		while (*B->head->content != max)
		{
			if (pos <= B->size / 2)
				rb(B);
			else
				rrb(B);
		}
		pa(A, B);
	}
}

void	put_chunk(t_stack *A, t_stack *B, int *current_idx, int range)
{
	int	size;

	size = A->size;
	while (size > 0)
	{
		if (A->head->rank <= *current_idx)
		{
			pb(A, B);
			(*current_idx)++;
			size--;
		}
		else if (A->head->rank <= *current_idx + range)
		{
			pb(A, B);
			rb(B);
			(*current_idx)++;
			size--;
		}
		else
			ra(A);
	}
}

void	sort_large(t_stack *A, t_stack *B)
{
	int	range;
	int	current_idx;

	if (A->size <= 100)
		range = 15;
	else
		range = 30;
	current_idx = 0;
	put_chunk(A, B, &current_idx, range);
	push_back_to_a(A, B);
}
