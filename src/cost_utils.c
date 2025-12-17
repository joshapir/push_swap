/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:36:34 by joshapir          #+#    #+#             */
/*   Updated: 2025/04/22 21:01:32 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*find_smallest(t_stack *stack)
{
	t_stack	*smallest_node;
	t_stack	*current;
	long	smallest;

	current = stack;
	smallest_node = NULL;
	smallest = LONG_MAX;
	while (current)
	{
		if (current -> value < smallest)
		{
			smallest = current -> value;
			smallest_node = current;
		}
		current = current -> next;
	}
	return (smallest_node);
}

t_stack	*find_largest(t_stack *stack)
{
	t_stack	*largest_node;
	long	largest;

	largest_node = NULL;
	largest = LONG_MIN;
	while (stack)
	{
		if (stack -> value > largest)
		{
			largest = stack -> value;
			largest_node = stack;
		}
		stack = stack -> next;
	}
	return (largest_node);
}

t_stack	*find_cheapest(t_stack *stack)
{
//	t_stack	*node;
	t_stack	*cheapest;
	long	cost;

//	node = stack;
	cost = LONG_MAX;
	while (stack)
	{
		if (stack -> push_cost + stack -> target_node -> push_cost < cost)
		{
			cost = stack -> push_cost + stack -> target_node -> push_cost;
			cheapest = stack;
		}
		stack = stack -> next;
	}
	cheapest -> cheapest = true;
	cheapest -> target_node -> cheapest = true;
	return (cheapest);
}

void	calculate_push_cost(t_stack *stack)
{
//	long	push_cost;
	long	len;

	len = stack_len(stack);
	find_index_of_stack(stack);
	is_above_median(stack);
//	push_cost = 0;
	while (stack)
	{
		if (stack -> above_median == true)
			stack -> push_cost = stack->index;
		else
			stack -> push_cost = len - stack -> index;
		stack = stack -> next;
	}
}
