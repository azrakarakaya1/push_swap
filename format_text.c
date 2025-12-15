/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_text.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azkaraka <azkaraka@student.42istanbul.com  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:18:59 by azkaraka          #+#    #+#             */
/*   Updated: 2025/12/08 14:19:05 by azkaraka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**split_free(char **str, int i)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
	return (NULL);
}

static int	count_words(char const *str, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i])
			count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static char	*get_next_word(char const *str, char c, int *index)
{
	char	*word;
	int		len;
	int		start;
	int		i;

	len = 0;
	while (str[*index] == c)
		(*index)++;
	start = *index;
	while (str[*index] && str[*index] != c)
	{
		(*index)++;
		len++;
	}
	word = malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		words;
	int		i;
	int		index;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	result = malloc((words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	index = 0;
	while (i < words)
	{
		result[i] = get_next_word(s, c, &index);
		if (!result[i])
			return (split_free(result, i));
		i++;
	}
	result[i] = NULL;
	return (result);
}
