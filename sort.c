/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 10:52:59 by ayfadli           #+#    #+#             */
/*   Updated: 2026/01/03 11:36:55 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	counter;
	int	range;
	int	top;

	counter = 0;
	if (stack_a->size <= 100)
		range = 15;
	else
		range = 30;
	while (stack_a->size > 0)
	{
		if (top = stack_a->data[0] <= counter)
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

void chunk_sort(t_stack *stack_a, t_stack	*stack_b)
{
	if (stack_a->size == 2)
		sa(stack_a);
	else if (stack_a->size == 3)
		sort_three(stack_a);
	else if (stack_a->size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_to_b(stack_a, stack_b);
}
