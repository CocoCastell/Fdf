/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:46:21 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 11:49:30 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	handle_negative(int *nb, int *n, char *str, int *i)
{
	if (*nb == -2147483648)
	{
		str[*i] = '8';
		(*i)++;
		*nb = 214748364;
	}
	else
	{
		*n = -1;
		*nb = -(*nb);
	}
}

int	get_length(int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char	*handle_zero(void)
{
	char	*str;

	str = malloc(2);
	if (!str)
		return (NULL);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char	*handle_positive(int nb, char *str, int *i)
{
	while (nb != 0)
	{
		str[*i] = (nb % 10) + '0';
		(*i)++;
		nb /= 10;
	}
	return (str);
}

char	*ft_itoa(int nb)
{
	int		n;
	int		len;
	int		i;
	char	*str;

	n = 1;
	len = 0;
	i = 0;
	str = NULL;
	if (nb == 0)
		return (handle_zero());
	if (nb < 0)
		handle_negative(&nb, &n, str, &i);
	len = get_length(nb);
	if (n == -1)
		len++;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	handle_positive(nb, str, &i);
	if (n == -1)
		str[i++] = '-';
	str[i] = '\0';
	ft_strrev(str);
	return (str);
}
