/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:36:05 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/29 15:46:43 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*delete_first(t_stack *stack)
{
	int	size;
	int	*new_arr;
	int	i;

	size = stack->size;
	if (size == 1)
	{
		free(stack->data);
		stack->size--;
		return (NULL);
	}
	new_arr = malloc(sizeof(int) * (size - 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	while (i < size - 1)
	{
		new_arr[i] = stack->data[i + 1];
		i++;
	}
	stack->size--;
	free(stack->data);
	return (new_arr);
}

int	*add_top(t_stack *stack, int value)
{
	int	size;
	int	i;
	int	*new_arr;

	size = stack->size;
	new_arr = malloc(sizeof(int) * (size + 1));
	if (!new_arr)
		return (NULL);
	i = 0;
	new_arr[0] = value;
	while (i < size)
	{
		new_arr[i + 1] = stack->data[i];
		i++;
	}
	stack->size++;
	free(stack->data);
	return (new_arr);
}

void	push(t_stack *src, t_stack *des)
{
	int	value;

	if (src->size == 0)
		return ;
	value = src->data[0];
	src->data = delete_first(src);
	des->data = add_top(des, value);
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
