/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 13:06:10 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/20 10:16:13 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	full_exit(t_stack *stack)
{
	write(2, "Error!\n", 7);
	stack_clear(stack);
	exit(2);
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
