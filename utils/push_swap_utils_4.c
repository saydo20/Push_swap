/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:06:10 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/17 13:40:42 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort(t_stack *A, t_stack *B)
{
	if (A->size == 2)
	{
		sa(A);
		return ;
	}
	if (A->size == 3)
		sort_3(A);
	else if (A->size == 5 || A->size == 4)
		sort_5(A, B);
	else
		sort_large(A, B);
}

int	stack_size(t_stack *stack)
{
	t_list	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_list	*creat_node(int a)
{
	t_list	*ptr;
	int		*num;

	ptr = malloc(sizeof(t_list));
	if (!ptr)
		return (NULL);
	num = malloc(sizeof(int));
	if (!num)
	{
		free(ptr);
		return (NULL);
	}
	*num = a;
	ptr->content = num;
	ptr->next = NULL;
	ptr->prev = NULL;
	ptr->rank = -1;
	return (ptr);
}

int	find_pos_max(t_stack *stack)
{
	t_list	*tmp;
	int		max;
	int		pos;
	int		i;

	tmp = stack->head;
	max = *(tmp->content);
	pos = 0;
	i = 0;
	while (tmp)
	{
		if (*(tmp->content) > max)
		{
			max = *(tmp->content);
			pos = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (pos);
}

int	find_max(t_stack *stack)
{
	t_list	*tmp;
	int		max;
	int		i;

	tmp = stack->head;
	max = *(tmp->content);
	i = 0;
	while (tmp)
	{
		if (*(tmp->content) > max)
			max = *(tmp->content);
		tmp = tmp->next;
		i++;
	}
	return (max);
}
