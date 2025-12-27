/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sjdia <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 16:45:46 by sjdia             #+#    #+#             */
/*   Updated: 2025/12/20 10:23:11 by sjdia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 2
# endif

typedef struct s_list
{
	struct s_list	*next;
	struct s_list	*prev;
	int				*content;
	int				rank;
}	t_list;

typedef struct s_stack {
	t_list	*head;
	int		size;
}t_stack;

t_list	*creat_node(int a);
int		ft_strlen(const char *s);
int		is_valid_int(char *str);
int		count_words(const char *s, char c);
int		ft_atoi(char *str, t_stack *stack);
int		ft_strcmp(const char *s1, const char *s2);
int		find_pos(t_stack *stack, int number);
char	*ft_strdup(const char *s);
char	*fill_join(char *ptr, const char *s1, const char *s2);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*get_line(char *line);
char	*fill_line(int fd, char *buf, char **left);
char	*get_next_line(int fd);
char	**pars_list(char **ptr, t_stack *stack);
char	*mft_strdup(char *s, size_t start, size_t end);
char	**fill(char **ptr, char *s, char c);
char	**ft_split(char const *s, char c);
void	free_ptr(char **ptr, int i, t_stack *A);
void	check_duplicates(t_stack *stack);
void	fill_ptr(char **av, t_stack *A);
void	stack_clear(t_stack *stack);
void	full_exit(t_stack *stack);
void	*free_split(int index, char **s);
void	add_node_back(t_stack *stack, t_list *node);

//opirations
void	pa(t_stack *A, t_stack *B);
void	pb(t_stack *A, t_stack *B);
void	rra(t_stack *A);
void	rrb(t_stack *B);
void	rrr(t_stack *A, t_stack *B);
void	sa(t_stack *A);
void	sb(t_stack *B);
void	ss(t_stack *A, t_stack*B);
void	ra(t_stack *A);
void	rb(t_stack *B);
void	rr(t_stack *A, t_stack *B);
#endif
