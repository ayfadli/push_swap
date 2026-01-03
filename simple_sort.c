/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 10:29:09 by ayfadli           #+#    #+#             */
/*   Updated: 2026/01/03 10:29:36 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack *stack)
{
	int	*data;

	data = stack->data;
	if (data[1] > data[0] && data[1] > data[2] && data[2] > data[0])
	{
		sa(stack);
		ra(stack);
	}
	else if (data[0] < data[2] && data[0] > data[1])
		sa(stack);
	else if (data[1] > data[0] && data[1] > data[2])
		rra(stack);
	else if (data[0] > data[2] && data[1] < data[2])
		ra(stack);
	else
	{
		sa(stack);
		rra(stack);
	}
}

int	find_min_pos(t_stack *stack)
{
	int	i;
	int	min;
	int	min_pos;

	min_pos = 0;
	i = 0;
	min = stack->data[0];
	while (i < stack->size)
	{
		if (min > stack->data[i])
		{
			min = stack->data[i];
			min_pos = i;
		}
		i++;
	}
	return (min_pos);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;

	while (stack_a->size > 3)
	{
		min_pos = find_min_pos(stack_a);
		if (min_pos <= stack_a->size / 2)
		{
			while (min_pos--)
				ra(stack_a);
		}
		else
		{
			min_pos = stack_a->size - min_pos;
			while (min_pos--)
				rra(stack_a);
		}
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (stack_b->size > 0)
		pa(stack_a, stack_b);
}
