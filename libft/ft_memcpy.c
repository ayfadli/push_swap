/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 10:00:30 by ayfadli           #+#    #+#             */
/*   Updated: 2025/11/05 13:49:09 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*tmp_src;
	char	*tmp_dest;

	if (!dest && !src)
		return (dest);
	tmp_dest = (char *)dest;
	tmp_src = (char *)src;
	while (n--)
		*(tmp_dest++) = *(tmp_src++);
	return (dest);
}
