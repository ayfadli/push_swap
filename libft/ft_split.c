/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayfadli <ayfadli@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 19:48:28 by ayfadli           #+#    #+#             */
/*   Updated: 2025/11/06 11:44:26 by ayfadli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char c)
{
	int	i;
	int	in_word;
	int	count;

	if (!str)
		return (0);
	count = 0;
	in_word = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (str[i] == c)
			in_word = 0;
		i++;
	}
	return (count);
}

static void	free_all(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

static char	*word_dup(char *s, char c, int start)
{
	char	*word;
	int		j;
	int		len;

	j = start;
	while (s[j] && s[j] != c)
		j++;
	len = j - start;
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (j < len)
	{
		word[j] = s[start + j];
		j++;
	}
	word[j] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		i;
	int		w;

	if (!s)
		return (NULL);
	strs = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
	if (!strs)
		return (NULL);
	i = 0;
	w = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (!s[i])
			break ;
		strs[w] = word_dup((char *)s, c, i);
		while (s[i] != c && s[i])
			i++;
		if (!strs[w])
			return (free_all(strs, w), NULL);
		w++;
	}
	return (strs[w] = NULL, strs);
}
