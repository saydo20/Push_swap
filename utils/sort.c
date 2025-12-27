/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 16:43:03 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/27 12:33:30 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_max_or_second(t_stack *A, t_stack *B, int max)
{
	int	second;
	int	pos_max;
	int	pos_second;

	second = find_second_max(B, max);
	pos_max = find_pos(B, max);
	pos_second = find_pos(B, second);
	if ((pos_second <= B->size / 2 && pos_second < pos_max)
		|| (pos_second > B->size / 2 && pos_second > pos_max))
	{
		rotate_to_top(B, second);
		pa(A, B);
		rotate_to_top(B, max);
		pa(A, B);
		sa(A);
	}
	else
	{
		rotate_to_top(B, max);
		pa(A, B);
	}
}

void	push_back_to_a(t_stack *A, t_stack *B)
{
	int	max;

	while (B->size > 0)
	{
		max = find_max(B);
		if (B->size < 2)
		{
			rotate_to_top(B, max);
			pa(A, B);
			continue ;
		}
		push_max_or_second(A, B, max);
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
