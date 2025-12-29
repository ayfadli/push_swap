/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 14:18:31 by ayfadli           #+#    #+#             */
/*   Updated: 2025/11/07 18:07:19 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(const char *s, const char *set)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_strchr(set, s[i]))
			return (i);
		i++;
	}
	return (i);
}

static int	get_end(const char *s, const char *set)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i >= 0)
	{
		if (!ft_strchr(set, s[i]))
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*trim;
	int		len;

	if (!s1 || !set)
		return (NULL);
	start = get_start(s1, set);
	end = get_end(s1, set);
	if (start <= end)
		len = end - start + 1;
	else
		len = 0;
	trim = malloc(sizeof(char) * (len + 1));
	if (!trim)
		return (NULL);
	ft_memmove(trim, &s1[start], len);
	trim[len] = '\0';
	return (trim);
}
