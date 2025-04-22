/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 01:43:53 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/05 19:38:04 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	free_stack(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (!stack)
		return (0);
	while (tmp)
	{
		*stack = (*stack)-> next;
		free(tmp);
		tmp = *stack;
	}
	return (0);
}
/*
int main (void)
{
	t_stack *a;
	t_stack *b;
	t_stack *c;
   
	a = malloc(sizeof(t_stack));
	a -> value = 1;
	b = malloc(sizeof(t_stack));
	c = malloc(sizeof(t_stack));
	c -> next = NULL;
	b -> next = c;
	a->next = b;
	a->next->value = 5;
	a -> value = 2;

	free_stack (&b);
	a->next = NULL;
	free_stack(&a);
	return (0);	
}
*/
