/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 16:50:39 by ayfadli           #+#    #+#             */
/*   Updated: 2025/11/05 16:36:38 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*tmp_str;

	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	tmp_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (tmp_str == NULL)
		return (NULL);
	ft_strlcat(tmp_str, s1, (s1_len + s2_len + 1));
	ft_strlcat(tmp_str, s2, (s1_len + s2_len + 1));
	return (tmp_str);
}
