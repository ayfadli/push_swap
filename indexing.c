/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 11:39:11 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/29 17:41:05 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
}

static int	get_rank(int num, int *sorted_arr, int size)
{
	int	j;

	j = 0;
	while (j < size)
	{
		if (num == sorted_arr[j])
			return (j);
		j++;
	}
	return (0);
}

void	index_stack(t_stack *stack)
{
	int	*temp_arr;
	int	i;

	temp_arr = malloc(sizeof(int) * stack->size);
	if (!temp_arr)
		error_exit(NULL, NULL, NULL, NULL);
	i = 0;
	while (i < stack->size)
	{
		temp_arr[i] = stack->data[i];
		i++;
	}
	sort_int_tab(temp_arr, stack->size);
	i = 0;
	while (i < stack->size)
	{
		stack->data[i] = get_rank(stack->data[i], temp_arr, stack->size);
		i++;
	}
	free(temp_arr);
}
