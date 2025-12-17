/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:36:43 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/11 21:16:33 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"

t_stack	*ft_lstnew(int value)
{
	t_stack	*new;

	new = (void *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new -> value = value;
	new -> next = NULL;
	return (new);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*buffer;

	if (lst == NULL || new == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	buffer = ft_lstlast(*lst);
	if (buffer != NULL)
		buffer -> next = new;
	new -> next = NULL;
}
/*
void	print_list(t_stack **lst, char list)
{
	t_stack	*tmp;

	tmp = *lst;
	if (list == 'a')
		write(1, "STACK A: ", 9);
	else
		write (1, "STACK B: ", 9);
	while (tmp != NULL)
	{
		printf("%ld", tmp->value);
		if (tmp->next != NULL)
			printf(" -> ");
		tmp = tmp->next;
	}
	write (1, "\n", 1);
}
*/

void	rrr(t_stack **a, t_stack **b)
{
	if (a)
		reverse_rotate(&(*a), 'r');
	if (b)
		reverse_rotate(&(*b), 'r');
}
