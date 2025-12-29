/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:52:07 by ayfadli           #+#    #+#             */
/*   Updated: 2025/11/05 13:47:44 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	tmp_char;
	unsigned char	*tmp_str;
	size_t			i;

	tmp_char = (unsigned char)c;
	tmp_str = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		tmp_str[i] = tmp_char;
		i++;
	}
	return (s);
}
