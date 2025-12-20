/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:31 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/20 11:19:25 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_node_back(t_stack *stack, t_list *node)
{
	t_list	*tmp;

	if (!stack->head)
	{
		stack->head = node;
	}
	else
	{
		tmp = stack->head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = node;
		node->prev = tmp;
	}
	stack->size++;
}

t_list	*find_min(t_stack *stack)
{
	t_list	*current;
	t_list	*min_node;
	int		min_value;
	int		found_first;

	current = stack->head;
	found_first = 0;
	while (current)
	{
		if (!found_first && current->rank == -1)
		{
			min_node = current;
			min_value = *current->content;
			found_first = 1;
		}
		else if (*current->content < min_value && current->rank == -1)
		{
			min_node = current;
			min_value = *current->content;
		}
		current = current->next;
	}
	return (min_node);
}

void	assign_index(t_stack *stack)
{
	t_list	*node;
	int		index;

	node = stack->head;
	index = 0;
	while (index < stack->size)
	{
		node = find_min(stack);
		if (node != NULL)
			node->rank = index;
		index++;
	}
}

int	is_sorted(t_stack *stack)
{
	t_list	*tmp;

	if (!stack || !stack->head)
		return (1);
	tmp = stack->head;
	while (tmp->next)
	{
		if (*(tmp->content) > *(tmp->next->content))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_stack	a;
	t_stack	b;

	a.head = NULL;
	a.size = 0;
	b.head = NULL;
	b.size = 0;
	if (ac < 2)
		return (0);
	fill_ptr(av, &a);
	check_duplicates(&a);
	if (is_sorted(&a))
	{
		stack_clear(&a);
		return (0);
	}
	assign_index(&a);
	sort(&a, &b);
	stack_clear(&a);
	stack_clear(&b);
	return (0);
}
