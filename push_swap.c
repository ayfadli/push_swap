/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:29:11 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/29 17:47:01 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	parse_args(t_stack *stack_a, char *args, t_stack *stack_b)
{
	char	**data;
	int		i;

	data = ft_split(args, ' ');
	if (!data || !*data)
		error_exit(stack_a, NULL, args, stack_b);
	i = 0;
	while (data[i])
	{
		if (!is_valid_input(data[i]))
			error_exit(stack_a, data, args, stack_b);
		i++;
	}
	stack_a->size = i;
	stack_a->data = fill_from_split(data, i);
	if (!stack_a->data)
		error_exit(stack_a, data, args, stack_b);
	free_split(data);
}

static void	check_duplicates(t_stack *stack, char *args, t_stack *stack_b)
{
	int	i;
	int	j;

	i = 0;
	while (i < stack->size)
	{
		j = i + 1;
		while (j < stack->size)
		{
			if (stack->data[i] == stack->data[j])
				error_exit(stack, NULL, args, stack_b);
			j++;
		}
		i++;
	}
}

void	free_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a)
	{
		free(stack_a->data);
		free(stack_a);
	}
	if (stack_b)
	{
		free(stack_b->data);
		free(stack_b);
	}
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*args;

	if (ac < 2)
		return (1);
	stack_a = malloc(sizeof(t_stack));
	stack_b = malloc(sizeof(t_stack));
	if (!stack_a || !stack_b)
		error_exit(stack_a, NULL, NULL, stack_b);
	args = join_args(ac, av, stack_a, stack_b);
	if (!args)
		error_exit(stack_a, NULL, NULL, stack_b);
	parse_args(stack_a, args, stack_b);
	check_duplicates(stack_a, args, stack_b);
	if (is_sorted(stack_a))
		return (free_stacks(stack_a, stack_b), free(args), 0);
	index_stack(stack_a);
	sort_to_b(stack_a, stack_b);
	return (free_stacks(stack_a, stack_b), free(args), 0);
}
