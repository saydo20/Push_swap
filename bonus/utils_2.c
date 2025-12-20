/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:55 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/20 10:15:41 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	check_duplicates(t_stack *stack)
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

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
