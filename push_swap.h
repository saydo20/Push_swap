/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:19:46 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/09 18:19:47 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

typedef struct s_list
{
	int		*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int ft_atoi(char *str);
char	**ft_split(char const *s, char c);
char **pars_list(char *str);
int check_duplicates(t_list *head);
void add_node_back(t_list **head, t_list *new);
t_list *creat_node(void *a);
char **pars_list_2(int ac, char **av, t_list *stack);
void	SA(t_list **A);
void	SB(t_list **B);
void    PA(t_list **A, t_list **B);
void    PB(t_list **A, t_list **B);
void    RA(t_list **A);
void    RB(t_list **B);
void    RR(t_list **A, t_list **B);
void    RRA(t_list **A);
void    RRB(t_list **B);
#endif