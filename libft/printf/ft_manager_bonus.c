/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:34:25 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/09 16:24:16 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf_bonus.h"

void	init_struct(t_parse *parsing)
{
	parsing->diez = false;
	parsing->space = false;
	parsing->plus = false;
	parsing->specifier = 'q';
	parsing->width = 1;
	parsing->sign = 0;
}

static int	hexa_manager(t_parse *parsing, long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (parsing->diez == true)
	{
		if (parsing->specifier == 'x')
			count += write(1, "0x", 2);
		if (parsing->specifier == 'X')
			count += write(1, "0X", 2);
	}
	if (parsing->specifier == 'x')
		count += print_int(nb, 16, 0);
	else if (parsing->specifier == 'X')
		count += print_int(nb, 16, 1);
	return (count);
}

static int	int_manager(t_parse *parsing, long nb)
{
	int	count;

	count = 0;
	if (parsing->plus == true && nb >= 0)
		count = write(1, "+", 1);
	if (parsing->space == true && parsing->plus == false && nb >= 0)
		count = write(1, " ", 1);
	count += print_int(nb, 10, 0);
	return (count);
}

int	manager(t_parse *parsing, char conversion, va_list ap)
{
	int	count;

	count = 0;
	if (conversion == 'c' || conversion == '%')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		count++;
	}
	else if (conversion == 's')
		count = printf_string(va_arg(ap, char *));
	else if (conversion == 'i' || conversion == 'd')
		count = int_manager(parsing, (long)va_arg(ap, int));
	else if (conversion == 'p')
		count = print_pointer(va_arg(ap, uintptr_t));
	else if (conversion == 'u')
		count = print_unsigned_int(va_arg(ap, unsigned int), 0);
	else if (conversion == 'x' || conversion == 'X')
		count = hexa_manager(parsing, (long)va_arg(ap, unsigned int));
	return (count);
}
