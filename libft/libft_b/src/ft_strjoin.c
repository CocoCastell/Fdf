/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 16:42:08 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/05 18:58:40 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	j;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	cat = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (cat == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		cat[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		cat[i] = s2[j];
		i++;
		j++;
	}
	cat[i] = '\0';
	return (cat);
}
