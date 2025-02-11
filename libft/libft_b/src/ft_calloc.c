/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:14:49 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/05 18:05:29 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*str;
	size_t	tot_size;
	size_t	i;

	tot_size = nmemb * size;
	str = malloc(tot_size);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i < tot_size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
