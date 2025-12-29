/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 11:37:42 by ayfadli           #+#    #+#             */
/*   Updated: 2025/11/04 10:34:46 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	i;

	i = 0;
	if (n < 10 && n >= 0)
		return (1);
	i++;
	return (i + count_digits(n / 10));
}

static void	ft_revstr(char *str, size_t len)
{
	int		i;
	int		j;
	char	temp;

	i = 0;
	j = len - 1;
	while (i < j)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
		i++;
		j--;
	}
}

static char	*fill_str(int n, long nb, size_t len)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (n < 0)
		str[len - 1] = '-';
	if (nb == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	while (nb)
	{
		str[i++] = nb % 10 + 48;
		nb /= 10;
	}
	str[len] = '\0';
	ft_revstr(str, len);
	return (str);
}

char	*ft_itoa(int n)
{
	long	nb;
	size_t	len;

	len = 0;
	nb = n;
	if (nb < 0)
	{
		nb = -nb;
		len += 1;
	}
	len += count_digits(nb);
	return (fill_str(n, nb, len));
}
