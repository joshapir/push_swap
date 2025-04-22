/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 20:59:48 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/10 20:08:10 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include <stdio.h>

void	swap(t_stack **stack, char list)
{
	long	tmp;

	if (!*stack || (*stack)->next == NULL)
		return ;
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	list = '\0';
	return ;
}

void	push(t_stack **stack_a, t_stack **stack_b, char stack)
{
	t_stack	*temp;

	if (!(*stack_a))
		return ;
	if (stack == 'a')
	{
		if (!(*stack_b))
			return ;
		temp = (*stack_b);
		(*stack_b) = (*stack_b)-> next;
		temp -> next = (*stack_a);
		*stack_a = temp;
	}
	else
	{
		temp = (*stack_a)-> next;
		(*stack_a)-> next = (*stack_b);
		(*stack_b) = (*stack_a);
		*stack_a = temp;
	}
}

void	rotate(t_stack **lst, char stack)
{
	t_stack	*tmp;
	t_stack	*current;

	if (!(*lst) || !lst || !(*lst)-> next)
		return ;
	current = (*lst);
	tmp = (*lst);
	while (current -> next)
		current = current -> next;
	current -> next = tmp;
	*lst = (*lst)-> next;
	tmp -> next = NULL;
	stack = '\0';
	return ;
}

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*tmp;
	t_stack	*new_last;
	int		i;

	if (!stack || !(*stack) || !(*stack)-> next)
		return ;
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
	c = '\0';
	return ;
	find_index_of_stack(*stack);
}

void	rr(t_stack **a, t_stack **b)
{
	if (a)
		rotate(&(*a), 'r');
	if (b)
		rotate(&(*b), 'r');
}
