/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:18:55 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:18:56 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../push_swap.h"

int ft_atoi(char *str)
{
    int sign;
    int i;
    long result;

    i = 0;
    sign = 1;
    result = 0;
    while((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if(str[i] == '-' || str[i] == '+')
    {
        if(str[i] == '-')
            sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
	{
        result = (result * 10) + (str[i] - '0');
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
		i++;
	}
    return (result * sign);
}

int check_duplicates(t_list *head)
{
    int i;
    while(head)
    {
        i = *(int *)head->content;
        while(head->next)
        {
            head = head->next;
            if(*(int *)head->content == i)
                return (0);
        }
        head = head->next;
    }
    return (1);
}
