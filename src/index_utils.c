/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:38:29 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/05 20:43:26 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	is_above_median(t_stack *stack)
{
	long	median;

	median = stack_len(stack) / 2;
	find_index_of_stack(stack);
	while (stack)
	{
		if (stack->index <= median)
			stack -> above_median = true;
		else
			stack -> above_median = false;
		stack = stack -> next;
	}
}

void	above_median(t_stack *stack, t_stack *stack2)
{
	long	median;

	median = stack_len(stack) / 2;
	while (stack)
	{
		if (stack->index <= median)
			stack -> above_median = true;
		else
			stack -> above_median = false;
		stack = stack -> next;
	}
	is_above_median(stack2);
}

void	find_index_of_stack(t_stack *stack)
{
	int		index;
	t_stack	*current;

	index = 0;
	current = stack;
	if (stack == NULL)
		return ;
	while (current != NULL)
	{
		current->index = index++;
		current = current->next;
	}
}

void	find_real_index(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*start;
	int		i;

	start = stack;
	tmp = stack;
	i = 0;
	while (stack)
	{
		tmp = start;
		while (tmp)
		{
			if (stack -> value > tmp -> value)
				i++;
			tmp = tmp -> next;
		}
		stack -> real_index = i;
		i = 0;
		stack = stack -> next;
	}
	stack = start;
}
