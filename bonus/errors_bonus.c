/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joshapir <joshapir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 04:03:22 by joshapir          #+#    #+#             */
/*   Updated: 2025/02/10 18:19:09 by joshapir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap_bonus.h"
#include <stdio.h>
#include <unistd.h>

//int	ft_atoi(const char *nptr);

int	ft_isdigit(char *str)
{
	int		i;
	long	num;

	i = 0;
	num = atol(str);
	if (num > INT_MAX || num < INT_MIN)
		return (0);
	if (str[0] == '-' && str[1] == '-')
		return (0);
	if (str[i] == '-' && str[++i] == '\0')
		return (0);
	if (str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] == ' ')
			i++;
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	if_duplicate(char **str)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	while (str[j])
	{
		i = j + 1;
		tmp = str[j];
		while (str [i])
		{
			if (ft_atoi(tmp) == ft_atoi(str[i]))
			{
				write(2, "Error\n", 6);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
