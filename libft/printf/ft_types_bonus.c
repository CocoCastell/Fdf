/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_types_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 16:00:32 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

int	printf_string(char *str)
{
	if (str == NULL)
		return (-1);
	else
		return (write(1, str, ft_strlen(str)));
}

int	print_pointer(uintptr_t int_ptr)
{
	char	*base_chars;
	char	str[17];
	int		count;
	int		i;

	if (int_ptr == 0)
		return (write(1, "(nil)", 5));
	count = write(1, "0x", 2);
	base_chars = "0123456789abcdef";
	i = 0;
	while (int_ptr != 0)
	{
		str[i] = base_chars[int_ptr % 16];
		int_ptr /= 16;
		i++;
	}
	str[i] = '\0';
	while (--i >= 0)
		count += write(1, &str[i], 1);
	return (count);
}

int	print_int(long nb, int base, int flag)
{
	char	*base_chars;
	int		count;

	if (flag == 0)
		base_chars = "0123456789abcdef";
	else if (flag == 1)
		base_chars = "0123456789ABCDEF";
	if (nb < 0)
	{
		write(1, "-", 1);
		return (print_int(-nb, base, flag) + 1);
	}
	if (nb < base)
		return (write(1, &base_chars[nb], 1));
	else
	{
		count = print_int(nb / base, base, flag);
		return (count + print_int(nb % base, base, flag));
	}
}

int	print_unsigned_int(unsigned int nb, int len)
{
	int		j;
	char	*str;

	j = nb;
	while (j > 9)
	{
		j /= 10;
		len++;
	}
	len++;
	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (write(2, "(null), malloc failed\n", 22));
	j = len - 1;
	while (j >= 0)
	{
		str[j] = nb % 10 + '0';
		j--;
		nb /= 10;
	}
	str[len] = '\0';
	j = write(1, str, ft_strlen(str));
	free(str);
	return (j);
}
