/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:55 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/11 10:04:11 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi_two(char *str, int i, int sign, t_stack *stack)
{
	long	result;

	result = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if (result > 2147483647 && sign == 1)
		{
			full_exit(stack);
		}
		else if (result > 2147483648 && sign == -1)
		{
			full_exit(stack);
		}
	}
	return (result);
}

int	ft_atoi(char *str, t_stack *stack)
{
	int		sign;
	int		i;
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
	result = ft_atoi_two(str, i, sign, stack);
	return (result * sign);
}

int	check_duplicates(t_stack *stack)
{
	t_list	*current;
	t_list	*runner;

	current = stack->head;
	while (current)
	{
		runner = current->next;
		while (runner)
		{
			if (*runner->content == *current->content)
				full_exit(stack);
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

void	stack_clear(t_stack *stack)
{
	t_list	*tmp;

	if (!stack)
		return ;
	while (stack->head)
	{
		tmp = stack->head->next;
		free(stack->head->content);
		free(stack->head);
		stack->head = tmp;
	}
	stack->size = 0;
}

void	sort_3(t_stack *A)
{
	int	a;
	int	b;
	int	c;

	a = *(A->head->content);
	b = *(A->head->next->content);
	c = *(A->head->next->next->content);
	if (a > b && a > c)
		ra(A);
	a = *(A->head->content);
	b = *(A->head->next->content);
	c = *(A->head->next->next->content);
	if (b > a && b > c)
		rra(A);
	a = *(A->head->content);
	b = *(A->head->next->content);
	if (a > b)
		sa(A);
}
