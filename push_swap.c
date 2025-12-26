#include "push_swap.h"
#include <stdio.h>

int check_args(char *arg)
{
	while(*arg)
	{
		if (!ft_strchr("0123456789 -", *arg))
			return (0);
		arg++;
	}
	return (1);
}

int	*char_to_int(char **data, t_stack *stack)
{
	int		w;
	int 	*numbers;

	w = 0;
	stack->size = w;
	numbers = malloc(sizeof(int) * w);
	if (!numbers)
		return (NULL);
	w = 0;
	while(data[w])
	{
		numbers[w] = ft_atoi(data[w]);
		w++;
	}
	return (numbers);
}

int	main(int ac, char **av)
{
	char	**data;
	t_stack *stack_a;
	int 	index;

	index = 1;
	stack_a = malloc(sizeof(t_stack));
	if (!stack_a)
		return (1);
	data = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
	{
		if (!check_args(av[1]))
			return (write(1,"ERROR",5), 1);
		data = ft_split(av[1], ' ');
		stack_a->data = char_to_int(data, stack_a);
	}
	else
	{
		stack_a->size = ac - 1;
		while(index < ac)
		{
			if (!check_args(av[index]))
				return (write(1,"ERROR",5), 1);
			printf("%d\n", stack_a->data[index - 1]);
			stack_a->data[index - 1] = ft_atoi(av[index]);
			index++;
		}
	}
	free(data);
	return(0);
}
