/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:03 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 17:21:06 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include "libft.h"
# include "get_next_line_bonus.h"

typedef struct s_parse
{
	bool	plus;
	bool	diez;
	bool	space;
	char	specifier;
	int		width;
	int		sign;
}				t_parse;

int		ft_printf(const char *format, ...);
int		print_unsigned_int(unsigned int nb, int len);
int		print_pointer(uintptr_t int_ptr);
int		print_int(long nb, int base, int flag);
int		printf_string(char *str);
int		manager(t_parse *parsing, char conversion, va_list ap);
int		check_diez(t_parse *parsing);
void	init_struct(t_parse *parsing);

#endif
