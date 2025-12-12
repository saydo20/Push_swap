/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:14 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 09:51:01 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *A)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*new_last;

	tmp = A->head;
	last = A->head;
	if (!A || !A->head)
		return ;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	A->head = last;
	last->next = tmp;
	last->prev = NULL;
	printf("rra\n");
}

void	rrb(t_stack *B)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*new_last;

	tmp = B->head;
	last = B->head;
	if (!B || !B->head)
		return ;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	B->head = last;
	last->next = tmp;
	last->prev = NULL;
	printf("rra\n");
}

void	rrr(t_stack *A, t_stack *B)
{
	rrb(B);
	rra(A);
	printf("rrr\n");
}
