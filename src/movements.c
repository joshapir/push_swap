/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:59:48 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/08 02:35:55 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

void	swap(t_stack **stack, char list)
{
	long	tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	if (list == 'a')
		write(1, "sa\n", 3);
	else if (list == 'b')
		write(1, "sb\n", 3);
	else
		return ;
}

void	push(t_stack **stack_a, t_stack **stack_b, char stack)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	if (stack == 'a')
	{
		temp = (*stack_b);
		(*stack_b) = (*stack_b)-> next;
		temp -> next = (*stack_a);
		*stack_a = temp;
		write(1, "pa\n", 3);
	}
	else
	{
		temp = (*stack_a)-> next;
		(*stack_a)-> next = (*stack_b);
		(*stack_b) = (*stack_a);
		*stack_a = temp;
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stack **lst, char stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!(*lst))
		return ;
	current = (*lst);
	tmp = (*lst);
	while (current -> next)
		current = current -> next;
	current -> next = tmp;
	*lst = (*lst)-> next;
	tmp -> next = NULL;
	if (stack == 'a')
		write(1, "ra\n", 3);
	else if (stack == 'b')
		write(1, "rb\n", 3);
	else
		return ;
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*new_last;
	int		i;

	i = 0;
	tmp = *stack;
	new_last = *stack;
	while (i < stack_len(*stack) - 2)
	{
		new_last = new_last -> next;
		i++;
	}
	while (tmp -> next != NULL)
		tmp = tmp-> next;
	new_last -> next = NULL;
	tmp ->next = *stack;
	(*stack)-> prev = *stack;
	*stack = tmp;
	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	else
		return ;
	find_index_of_stack(*stack);
}

void	rr(t_stack **a, t_stack **b)
{
	rotate(&(*a), 'r');
	rotate(&(*b), 'r');
	write(1, "rr\n", 3);
}
