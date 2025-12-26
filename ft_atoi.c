#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(char *str)
{
	int	result;
	int sign;

	sign = 1;
	result = 0;
	while (*str)
	{
		while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\f'
			|| *str == '\r' || *str == '\v')
				str++;
		if (*str == '+' || *str == '-')
		{
			if (*str == '-')
				sign = -1;
			str++;
			if(*str == '+' || *str == '-')
				return (0);
		}
		while(*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - 48;
			str++;
		}
		return (result * sign);
	}
}
