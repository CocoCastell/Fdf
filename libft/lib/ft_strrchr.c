/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:12:50 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/05 19:01:25 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	car;
	char	*ch;

	i = 0;
	ch = NULL;
	car = (char)c;
	while (s[i] != '\0')
	{
		if (s[i] == car)
			ch = (char *)&s[i];
		i++;
	}
	if (car == '\0')
		return ((char *)&s[i]);
	return (ch);
}
