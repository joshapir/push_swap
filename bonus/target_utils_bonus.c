/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   target_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:03:28 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/10 18:22:58 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

void	set_target_a(t_stack *a, t_stack *b)
{
	t_stack	*current_b;
	t_stack	*target;
	long	current_value;

	while (a)
	{
		current_value = LONG_MIN;
		current_b = b;
		target = NULL;
		while (current_b)
		{
			if (current_b->value < a->value && current_b->value > current_value)
			{
				current_value = current_b->value;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (target == NULL)
			a->target_node = find_largest(b);
		else
			a->target_node = target;
		a = a->next;
	}
}

void	set_target_b(t_stack *a, t_stack *b)
{
	t_stack	*current_a;
	t_stack	*target;
	long	current_value;

	while (b)
	{
		current_value = LONG_MAX;
		current_a = a;
		target = NULL;
		while (current_a)
		{
			if (current_a->value > b->value && current_a->value < current_value)
			{
				current_value = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (target == NULL)
			b->target_node = find_smallest(a);
		else
			b->target_node = target;
		b = b->next;
	}
}

void	target_to_top(t_stack **node, t_stack **stack, t_stack **s2, char list)
{
	if (!(*stack))
		return ;
	find_index_of_stack(*stack);
	find_index_of_stack(*s2);
	is_above_median(*stack);
	if ((*node)-> above_median == true)
	{
		if ((*node)-> index == 1)
			return (rotate(&(*stack), list));
		while ((*node)-> index != 0)
		{
			rotate(stack, list);
			find_index_of_stack(*stack);
		}
	}
	else
		while ((*node)-> index != 0)
			reverse_rotate(stack, list);
}
