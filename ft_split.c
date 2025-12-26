/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/26 10:20:48 by ayfadli           #+#    #+#             */
/*   Updated: 2025/12/26 10:21:23 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	count_words(char *str, char sep)
{
	int	count;
	int	new_word;

	count = 0;
	new_word = 1;
	while (*str)
	{
		if (*str != sep && new_word == 1)
		{
			new_word = 0;
			count++;
		}
		if (*str == sep)
			new_word = 1;
		str++;
	}
	return (count);
}

char	*wordcpy(char *str, char sep, int start)
{
	char	*word;
	int		len;
	int		i;

	i = start;
	while (str[i] && str[i] != sep)
		i++;
	len = i - start;
	word = malloc(sizeof(char) * (len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[start + i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	free_all(char **strs, int words)
{
	int	w;

	w = 0;
	while (w < words)
	{
		free(strs[w]);
		w++;
	}
	free(strs);
}

char	**ft_split(char *str, char sep)
{
	char	**strs;
	int		i;
	int		w;

	if (!str)
		return (NULL);
	i = 0;
	w = 0;
	strs = malloc((count_words(str, sep) + 1) * sizeof(char *));
	if (!strs)
		return (NULL);
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (!str[i])
			break ;
		strs[w] = wordcpy(str, sep, i);
		if (!strs[w])
			return (free_all(strs, w), NULL);
		while (str[i] && str[i] != sep)
			i++;
		w++;
	}
	return (strs[w] = NULL, strs);
}
