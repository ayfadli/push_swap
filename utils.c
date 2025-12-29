/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:34:30 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/29 17:34:24 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_valid_input(char *arg)
{
	if (*arg == '+' || *arg == '-')
		arg++;
	if (!*arg)
		return (0);
	while (*arg)
	{
		if (!ft_isdigit(*arg))
			return (0);
		arg++;
	}
	return (1);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (!str)
		return ;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	error_exit(t_stack *stack_a, char **data, char *args, t_stack *stack_b)
{
	if (data)
		free_split(data);
	if (stack_a)
	{
		if (stack_a->data)
			free(stack_a->data);
		free(stack_a);
	}
	if (stack_b)
	{
		if (stack_b->data)
			free(stack_b->data);
		free(stack_b);
	}
	if (args)
		free(args);
	write(2, "Error\n", 6);
	exit(1);
}

char	*free_and_join(char *s1, char *s2, t_stack *stack, t_stack *stack_b)
{
	char	*tmp;

	tmp = s1;
	tmp = ft_strjoin((const char *)tmp, (const char *)s2);
	free(s1);
	if (!tmp)
		error_exit(stack, NULL, NULL, stack_b);
	return (tmp);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size - 1)
	{
		if (stack->data[i] > stack->data[i + 1])
			return (0);
		i++;
	}
	return (1);
}
