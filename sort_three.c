/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 19:22:52 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/05 19:22:56 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*largest;
	t_stack	*smallest;

	find_index_of_stack(*stack);
	largest = find_largest(*stack);
	smallest = find_smallest(*stack);
	if (is_sorted(*stack))
		return ;
	if (largest -> index == 1)
	{
		if (smallest -> index == 0)
			return (reverse_rotate(stack, 'a'), swap(stack, 'a'));
		else
			return (reverse_rotate(stack, 'a'));
	}
	if (largest -> index == 0)
	{
		if (smallest -> index == 2)
			return (reverse_rotate(&(*stack), 'a'), swap(stack, 'a'));
		else
			rotate(stack, 'a');
	}
	else
		swap(stack, 'a');
	find_index_of_stack(*stack);
}

void	push_three(t_stack **stack_a, t_stack **stack_b)
{
	long	i;
	long	len;

	i = 0;
	len = stack_len(*stack_a);
	find_real_index(*stack_a);
	while (i < len / 2)
	{
		if ((*stack_a)->real_index < len / 2)
		{
			push(stack_a, stack_b, 'b');
			i++;
		}
		else
			rotate(stack_a, 'a');
	}
}
