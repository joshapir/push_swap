/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 05:56:21 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/11 21:15:23 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>

/*
   void	ft_putstr(char *str)
   {
   int	i;

   i = 0;
   while (str[i])
   write(1, &str[i++], 1);
   }*/

char	**init_str(char **argv, int argc)
{
	int		i;
	int		j;
	char	**str;

	i = 1;
	j = 0;
	str = NULL;
	str = malloc((argc) * sizeof(char *));
	if (!str)
		return (free(str), NULL);
	while (i < argc)
	{
		if (!ft_isdigit(argv[i]))
			return (write(2, "Error\n", 6), free(str), NULL);
		str[j] = argv[i];
		i++;
		j++;
	}
	str[j] = NULL;
	return (str);
}

void	ft_free(char **arr, char **argv)
{
	int	j;

	j = 0;
	if (!arr)
		return ;
	{
		while (arr[j] && arr[j] != argv[j + 1])
			free (arr[j++]);
		free(arr);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	char	**str;

	a = NULL;
	b = NULL;
	str = NULL;
	if (argc < 2)
		return (0);
	else if ((argc == 2 && !argv[1][1]) || argv[1][0] == '\0')
		return (write(2, "Error\n", 6), 0);
	str = init_str(argv, argc);
	if (!str)
		return (free_stack(&a), free_stack(&b), ft_free (str, argv), 0);
	if (if_duplicate(str) == 1)
		return (free_stack(&a), free_stack(&b), ft_free (str, argv), 0);
	if (!init_stack(&a, str))
		return (free_stack(&a), ft_free (str, argv), 0);
	if (is_sorted(a) == true)
		return (printf("OK\n"), free_stack(&a), ft_free (str, argv), (0));
	algorithm(&a, &b);
	return (free_stack(&a), ft_free (str, argv), 0);
}
