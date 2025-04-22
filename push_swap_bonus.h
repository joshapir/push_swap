/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/15 16:49:48 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/11 21:32:06 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
//# include <stdio.h>

typedef struct s_stack
{
	long			value;
	long			index;
	long			real_index;
	long			push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;

}	t_stack;

int		free_stack(t_stack **stack);
int		init_stack(t_stack **stack, char **argv);
int		ft_atol(char *str, int *num);
int		ft_isdigit(char *str);
int		if_duplicate(char **str);
int		ft_atoi(char *nptr);
int		ft_strcmp(char *str, char *str2);
long	find_index(t_stack *node, t_stack *stack);
long	stack_len(t_stack *stack);
bool	is_list_sorted(t_stack *stack);
bool	is_sorted(t_stack *stack);
void	set_target_a(t_stack *a, t_stack *b);
void	set_target_b(t_stack *a, t_stack *b);
void	above_median(t_stack *stack, t_stack *stack2);
void	calculate_push_cost(t_stack *stack);
void	algorithm(t_stack **stack_a, t_stack **stack_b);
void	target_to_top(t_stack **node, t_stack **stack, t_stack **s2, char list);
void	reverse_rotate(t_stack **stack, char c);
void	rr(t_stack **a, t_stack **b);
void	swap(t_stack **lst, char stack);
void	push(t_stack **stack_a, t_stack **stack_b, char stack);
void	prev_node(t_stack *stack);
void	find_index_of_stack(t_stack *stack);
void	print_list(t_stack **lst, char list);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	print_move(char *new_move, int j);
void	find_real_index(t_stack *stack);
void	check_rotate_both(t_stack **node, t_stack **stack_a, t_stack **stack_b);
void	rrr(t_stack **a, t_stack **b);
void	is_above_median(t_stack *stack);
void	sort_three(t_stack **stack);
void	push_three(t_stack **stack_a, t_stack **stack_b);
void	turk(t_stack **stack_a, t_stack **stack_b);
void	swap(t_stack **stack, char list);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	print_list(t_stack **lst, char list);
void	push(t_stack **stack_a, t_stack **stack_b, char stack);
void	rotate(t_stack **lst, char stack);
void	reverse_rotate(t_stack **stack, char c);
void	rr(t_stack **a, t_stack **b);
void	rrr(t_stack **a, t_stack **b);
void	ss(t_stack **a, t_stack **b);
int		init(t_stack **a, t_stack **b, char **str);
void	ft_free(t_stack **a, t_stack **b);
char	**ft_split(char const *s, char c);
char	**init_str(char **argv, int argc);
char	*get_next_line(int fd);
char	*ft_strchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *buffer, char *next);
char	*fill_next(int fd, char *next, ssize_t bytes_read);
char	*construct_line(char *next);
char	*clean_next(char *next);
char	*get_next_line(int fd);

t_stack	*find_largest(t_stack *stack);
t_stack	*find_smallest(t_stack *stack);
t_stack	*find_cheapest(t_stack *stack);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstnew(int value);
t_stack	*ft_lstlast(t_stack *lst);
#endif
