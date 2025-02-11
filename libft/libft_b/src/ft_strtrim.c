/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:32:26 by cochatel          #+#    #+#             */
/*   Updated: 2024/09/27 15:06:11 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static size_t	str_begin(char const *str, char const *set)
{
	size_t	i;
	size_t	j;
	int		c;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		c = 0;
		while (set[j] != '\0')
		{
			if (str[i] == set[j])
				c++;
			j++;
		}
		if (c == 0)
			break ;
		i++;
	}
	if (i == (ft_strlen(str)))
		return (ft_strlen(str));
	return (i);
}

static size_t	check(char const *s, char const *set, size_t i)
{
	size_t	j;
	size_t	count;

	count = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] != s[i])
				j++;
			else
				break ;
		}
		if (set[j] == '\0')
			return (0);
		else
			count++;
		i++;
	}
	return (count);
}

static size_t	str_end(char const *s, char const *set, size_t i)
{
	size_t	count;
	int		j;

	count = 0;
	while (s[i] != '\0')
	{
		j = 0;
		while (set[j] != '\0')
		{
			if (set[j] == s[i])
			{
				count = check(s, set, i);
				if (count != 0)
					return (count);
			}
			j++;
		}
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	len;
	size_t	beg;
	size_t	end;
	size_t	i;

	i = 0;
	beg = str_begin(s1, set);
	end = str_end(s1, set, beg);
	len = ft_strlen(s1) - end - beg;
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = s1[beg];
		beg++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*int	main(void)
{
	char	*s1;
	s1 = "lorem ipsum dolor sit amet";
        char	*f;
	f = ft_strtrim(s1, "te");
	printf("%s", f);
	free(f);
}*/
