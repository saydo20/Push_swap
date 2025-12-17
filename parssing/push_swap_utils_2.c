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

int	ft_atoi_two(char *str, int i, int sign, long result)
{
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i++] - '0');
		if (result > 2147483647 && sign == 1)
		{
			printf("error!\n");
			exit(1);
		}
		else if (result > 2147483648 && sign == -1)
		{
			printf("error!\n");
			exit(1);
		}
	}
	return (result);
}

int	ft_atoi(char *str)
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
	result = ft_atoi_two(str, i, sign, result);
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
			{
				printf("error!\n");
				stack_clear(stack);
				exit(1);
			}
			runner = runner->next;
		}
		current = current->next;
	}
	return (1);
}

int	distance_to_value(t_stack *stack, int index)
{
	t_list	*tmp;
	int		i;

	tmp = stack->head;
	i = 0;
	while (tmp)
	{
		if (*(int *)tmp->content == index)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (-1);
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
