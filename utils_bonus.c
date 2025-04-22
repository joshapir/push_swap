/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:38:32 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/10 18:23:10 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_atoi(char *nptr)
{
	int	result;	
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (nptr == NULL)
		return (0);
	if (nptr[i] == ' ')
	{
		while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
			i++;
	}
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
		result = result * 10 + (nptr[i++] - '0');
	return (sign * result);
}

int	init_stack(t_stack **stack, char **argv)
{
	int		i;
	t_stack	*new_node;
	t_stack	*current;

	i = 0;
	current = NULL;
	while (argv[i])
	{
		new_node = malloc(sizeof(t_stack));
		if (!new_node)
			return (0);
		new_node->value = ft_atoi(argv[i]);
		new_node->next = NULL;
		if (*stack == NULL)
			*stack = new_node;
		else
			current->next = new_node;
		current = new_node;
		i++;
	}
	current -> next = NULL;
	return (1);
}
