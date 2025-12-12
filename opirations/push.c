/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:20:01 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 09:47:52 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stack *A, t_stack *B)
{
	t_list	*tmp;

	if (!B->head)
		return ;
	tmp = B->head;
	B->head = B->head->next;
	if (B->head)
		B->head->prev = NULL;
	tmp->next = A->head;
	if (A->head)
		A->head->prev = tmp;
	tmp->prev = NULL;
	A->head = tmp;
	A->size++;
	B->size--;
	printf("pa\n");
}

void	pb(t_stack *A, t_stack *B)
{
	t_list	*tmp;

	if (!A->head)
		return ;
	tmp = A->head;
	A->head = A->head->next;
	if (A->head)
		A->head->prev = NULL;
	tmp->next = B->head;
	if (B->head)
		B->head->prev = tmp;
	tmp->prev = NULL;
	B->head = tmp;
	A->size--;
	B->size++;
	printf("pb\n");
}
