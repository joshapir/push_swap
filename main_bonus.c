/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 20:52:24 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/11 21:19:08 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	init_movements(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp("pb", line))
		return (push(a, b, 'b'), 1);
	else if (!ft_strcmp("pa", line))
		return (push(a, b, 'a'), 1);
	else if (!ft_strcmp("ra", line))
		return (rotate(a, 'a'), 1);
	else if (!ft_strcmp("rb", line))
		return (rotate(b, 'b'), 1);
	else if (!ft_strcmp("rr", line))
		return (rr(a, b), 1);
	else if (!ft_strcmp("rra", line))
		return (reverse_rotate(a, 'a'), 1);
	else if (!ft_strcmp("rrb", line))
		return (reverse_rotate(b, 'b'), 1);
	else if (!ft_strcmp("rrr", line))
		return (rrr(a, b), 1);
	else if (!ft_strcmp("sa", line))
		return (swap(a, 'a'), 1);
	else if (!ft_strcmp("sb", line))
		return (swap(b, 'b'), 1);
	else if (!ft_strcmp("ss", line))
		return (ss(a, b), 1);
	else
		return (0);
}

int	checker_loop(t_stack **a, t_stack **b)
{
	char	*line;
	char	*eol;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		eol = ft_strchr(line, '\n');
		if (eol)
			*eol = '\0';
		if (!init_movements(a, b, line))
			return (free(line), 0);
		free(line);
	}
	return (free(line), 1);
}

int	init(t_stack **a, t_stack **b, char **str)
{
	if (if_duplicate(str) == 1)
	{
		free_stack(a);
		free_stack(b);
		return (0);
	}
	if (!init_stack(a, str))
		return (ft_free(a, b), free (str), 0);
	if (!checker_loop(a, b))
	{
		write(2, "Error", 6);
		free_stack(a);
		free_stack(b);
		return (0);
	}
	return (1);
}

void	ft_free(t_stack **a, t_stack **b)
{
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	if ((argc == 2 && !argv[1][0]) || argv[1][0] == '\0')
		return (write(2, "Error\n", 6), free_stack(&a), free_stack(&b), 0);
	str = init_str(argv, argc);
	if (str == NULL)
		return (free_stack(&a), free(str), 0);
	if (!init(&a, &b, str))
		return (ft_free(&a, &b), free(str), 0);
	if (b)
		return ((write(1, "KO\n", 3), 0), ft_free(&a, &b), free(str), 0);
	if (is_sorted(a))
		return (write(1, "OK\n", 3), ft_free(&a, &b), free(str), 0);
	else
		return (write(1, "KO\n", 3), ft_free(&a, &b), free(str), 0);
	return (ft_free(&a, &b), free(str), 0);
}
