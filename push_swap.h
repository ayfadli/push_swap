/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 14:01:21 by ayfadli           #+#    #+#             */
/*   Updated: 2026/01/03 10:30:39 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
typedef struct s_stack
{
	int *data; // The actual array of integers
	int size;  // The size of array (number of elements in the stack)
}			t_stack;

typedef struct s_data
{
	t_stack	a;
	t_stack	b;
}			t_data;

int			is_valid_input(char *arg);
void		free_split(char **str);
void		error_exit(t_stack *stack_a, char **data, char *args,
				t_stack *stack_b);
char		*free_and_join(char *s1, char *s2, t_stack *stack,
				t_stack *stack_b);
int			is_sorted(t_stack *stack);

int			*fill_from_split(char **data, int size);
char		*join_args(int ac, char **av, t_stack *stack, t_stack *stack_b);

void		sa(t_stack *stack_a);
void		sb(t_stack *stack_b);
void		ss(t_stack *stack_a, t_stack *stack_b);

void		ra(t_stack *stack_a);
void		rb(t_stack *stack_b);
void		rr(t_stack *stack_a, t_stack *stack_b);

void		rrotate(t_stack *stack);
void		rra(t_stack *stack_a);
void		rrb(t_stack *stack_b);
void		rrr(t_stack *stack_a, t_stack *stack_b);

void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);

void		index_stack(t_stack *stack);
void		sort_to_b(t_stack *stack_a, t_stack *stack_b);

void		sort_three(t_stack *stack);
void		sort_five(t_stack *stack_a, t_stack *stack_b);

#endif
