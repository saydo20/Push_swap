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

// void	rra(t_stack *A)
// {
// 	t_list	*tmp;
// 	t_list	*last;
// 	t_list	*new_last;

// 	tmp = A->head;
// 	last = A->head;
// 	if (!A || !A->head)
// 		return ;
// 	while (last->next)
// 		last = last->next;
// 	new_last = last->prev;
// 	new_last->next = NULL;
// 	A->head = last;
// 	last->next = tmp;
// 	last->prev = NULL;
// 	write(1, "rra\n", 4);
// }

// void	rrb(t_stack *B)
// {
// 	t_list	*tmp;
// 	t_list	*last;
// 	t_list	*new_last;

// 	tmp = B->head;
// 	last = B->head;
// 	if (!B || !B->head)
// 		return ;
// 	while (last->next)
// 		last = last->next;
// 	new_last = last->prev;
// 	new_last->next = NULL;
// 	B->head = last;
// 	last->next = tmp;
// 	last->prev = NULL;
// 	write(1, "rrb\n", 4);
// }

void	rra(t_stack *A)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*new_last;

	if (!A || !A->head || !A->head->next)
		return ;
	tmp = A->head;
	last = A->head;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	A->head = last;
	last->next = tmp;
	last->prev = NULL;
	tmp->prev = last;
	write(1, "rra\n", 4);
}

void	rrb(t_stack *B)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*new_last;

	if (!B || !B->head || !B->head->next)
		return ;
	tmp = B->head;
	last = B->head;
	while (last->next)
		last = last->next;
	new_last = last->prev;
	new_last->next = NULL;
	B->head = last;
	last->next = tmp;
	last->prev = NULL;
	tmp->prev = last;
	write(1, "rrb\n", 4);
}

void	rrr(t_stack *A, t_stack *B)
{
	rrb(B);
	rra(A);
	write(1, "rrr\n", 4);
}
