/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:10:33 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/05 18:12:51 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*source;

	if (n == 0 || dest == src)
		return (dest);
	if (dest == NULL || src == NULL)
		return (NULL);
	i = 0;
	d = (unsigned char *)dest;
	source = (const unsigned char *)src;
	while (i < n)
	{
		d[i] = source[i];
		i++;
	}
	return (dest);
}
