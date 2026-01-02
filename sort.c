/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:52:59 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/29 15:48:25 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three(t_stack *stack)
{

	int *data = stack->data;

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

int find_min_pos(t_stack *stack)
{
	int i;
	int min;
	int min_pos;

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

void sort_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int counter;
	int range;
	int top;

	counter = 0;
	if (stack_a->size == 3)
	{
		sort_three(stack_a);
		return;
	}
	else if (stack_a->size <= 100)
		range = 15;
	else
		range = 30;
	while (stack_a->size > 0)
	{
		top = stack_a->data[0];
		if (top <= counter)
		{
			pb(stack_a, stack_b);
			rb(stack_b);
			counter++;
		}
		else if (top <= counter + range)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}
