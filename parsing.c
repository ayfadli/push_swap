/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:29:26 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/29 17:38:54 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(char *str)
{
	long	result;
	long	sign;

	result = 0;
	sign = 1;
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\r'
			|| *str == '\f')
			str++;
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -1;
			str++;
			if (*str == '+' || *str == '-')
				return (0);
		}
		while (ft_isdigit(*str))
		{
			result = result * 10 + *str - 48;
			str++;
		}
	}
	return (result * sign);
}

int	*fill_from_split(char **data, int size)
{
	int		*numbers;
	int		i;
	long	num;

	i = 0;
	numbers = malloc(sizeof(int) * size);
	if (!numbers)
		return (NULL);
	while (data[i])
	{
		num = ft_atol(data[i]);
		if (num > 2147483647 || num < -2147483648)
			return (free(numbers), NULL);
		numbers[i] = (int)num;
		i++;
	}
	return (numbers);
}

char	*join_args(int ac, char **av, t_stack *stack, t_stack *stack_b)
{
	int		i;
	char	*args;

	args = ft_strdup("");
	if (!args)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		args = free_and_join(args, av[i++], stack, stack_b);
		if (!args)
			error_exit(stack, NULL, NULL, stack_b);
		args = free_and_join(args, " ", stack, stack_b);

	}
	return (args);
}
