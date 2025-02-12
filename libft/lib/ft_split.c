/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:46:21 by cochatel          #+#    #+#             */
/*   Updated: 2025/01/21 14:28:24 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	cnt_words(char const *s, char c)
{
	int	i;
	int	j;

	if (s == NULL)
		return (0);
	j = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c && s[i + 1] != c)
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

static int	cnt_letters(char const *s, char c, size_t i)
{
	int	j;

	j = 0;
	while (s[i] != c && s[i] != '\0')
	{
		j++;
		i++;
	}
	return (j);
}

static void	free_str(char **s, int i)
{
	while (i > 0)
	{
		free(s[i - 1]);
		i--;
	}
	free(s);
}

static char	**str(char **arr, char const *s, char c, size_t index)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	while (index < ft_strlen(s))
	{
		j = 0;
		len = cnt_letters(s, c, index);
		arr[i] = malloc(len + 1);
		if (!arr[i])
			free_str(arr, i);
		while (j < len)
		{
			arr[i][j] = s[index];
			index++;
			j++;
		}
		arr[i][j] = '\0';
		i++;
		while (s[index] == c)
			index++;
	}
	arr[i] = NULL;
	return (arr);
}

char	**ft_split(char const *s, char c)
{
	size_t	index;
	char	**arr;

	if (!s)
		return (NULL);
	arr = malloc((cnt_words(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	index = 0;
	while (s[index] == c)
		index++;
	if (index == ft_strlen(s))
	{
		free (arr);
		arr = malloc(sizeof(char *));
		if (arr == NULL)
			return (NULL);
		arr[0] = NULL;
		return (arr);
	}
	arr = str(arr, s, c, index);
	return (arr);
}

/*#include <stdio.h>
int main()
{
	char **f = ft_split("", '.');
	for(int i = 0; f[i] != NULL; i++)
	{
		for(int j = 0; f[i][j] != '\0'; j++)
			printf("%c", f[i][j]);
		printf("\n");
	}
	free(f);
}*/
