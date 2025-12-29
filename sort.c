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

void	sort_to_b(t_stack *stack_a, t_stack *stack_b)
{
	int	counter;
	int	range;
	int top;

	counter = 0;
	if (stack_a->size <= 100)
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
		else if(top <= counter + range)
		{
			pb(stack_a, stack_b);
			counter++;
		}
		else
			ra(stack_a);
	}
}
