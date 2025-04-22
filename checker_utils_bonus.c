/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 21:01:27 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/10 20:29:51 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**init_str(char **argv, int argc)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	j = 0;
	str = malloc((argc) * sizeof(char *));
	if (!str)
		return (0);
	while (i < argc)
	{
		if (!ft_isdigit(argv[i]))
			return (write(2, "Error\n", 6), free (str), NULL);
		str[j] = argv[i];
		i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

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

int	ft_strcmp(char *str, char *str2)
{
	while (*str && (*str == *str2))
	{
		str++;
		str2++;
	}
	return (*(char *)str - *(char *)str2);
}
