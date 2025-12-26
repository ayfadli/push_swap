#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <stdlib.h>
# include <unistd.h>

char	**ft_split(char *str, char sep);
int		ft_strchr(char *str, char c);
int		ft_atoi(char *str);

typedef struct s_stack
{
	int	*data; //The actual array of integers
	int	size; //The size of array (number of elements in the stack)
} t_stack;

typedef struct s_data
{
	t_stack a;
	t_stack b;
} t_data;

#endif
