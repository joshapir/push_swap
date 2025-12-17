/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:10:32 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/11 18:49:19 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_stack *stack)
{
	if (!stack)
		return (1);
	while (stack -> next)
	{
		if (stack -> value > stack -> next -> value)
			return (false);
		stack = stack -> next;
	}
	return (true);
}

long	stack_len(t_stack *stack)
{
	long	count;

	count = 0;
	while (stack != NULL)
	{
		count++;
		stack = stack -> next;
	}
	return (count);
}

void	check_rotate_both(t_stack **node, t_stack **stack_a, t_stack **stack_b)
{
	if (((*node)-> index != 0) && ((*node)-> target_node -> index != 0))
	{
		if (((*node)-> above_median) && ((*node)-> target_node -> above_median))
		{
			while (((*node)-> index != 0) && \
	((*node)-> target_node -> index != 0))
			{
				rr(stack_a, stack_b);
				find_index_of_stack(*stack_a);
				find_index_of_stack(*stack_b);
			}
		}
		else if (((*node)-> above_median == false) && \
		((*node)-> target_node -> above_median == false))
		{
			while (((*node)-> index != 0) && \
			((*node)-> target_node -> index != 0))
			{
				rrr(stack_a, stack_b);
				find_index_of_stack((*stack_a));
				find_index_of_stack((*stack_b));
			}
		}
	}
}

void	turk(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;

	while (stack_len(*stack_b) != 0)
	{
		above_median(*stack_a, *stack_b);
		calculate_push_cost(*stack_b);
		calculate_push_cost(*stack_a);
		set_target_b(*stack_a, *stack_b);
		cheapest = find_cheapest(*stack_b);
		check_rotate_both(&cheapest, stack_a, stack_b);
		target_to_top(&cheapest -> target_node, stack_a, stack_b, 'a');
		target_to_top(&cheapest, &(*stack_b), stack_a, 'b');
		push(&(*stack_a), &(*stack_b), 'a');
	}
}

void	algorithm(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest;
	long	len;

	len = stack_len(*stack_a);
	if (stack_len(*stack_a) > 6)
		push_three(stack_a, stack_b);
	else if (len >= 5)
	{
		push(stack_a, stack_b, 'b');
		push(stack_a, stack_b, 'b');
	}
	else if (len == 4)
		push(stack_a, stack_b, 'b');
	while (stack_len(*stack_a) > 3)
		push(stack_a, stack_b, 'b');
	if (is_sorted(*stack_a) != true)
		sort_three(stack_a);
	turk (stack_a, stack_b);
	cheapest = find_smallest(*stack_a);
	find_index_of_stack(*stack_a);
	if (cheapest -> index != 0)
	{
		target_to_top(&cheapest, stack_a, stack_b, 'a');
		find_index_of_stack(*stack_a);
	}
}
