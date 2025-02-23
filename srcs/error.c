/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:46:19 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_error(char *msg, int error)
{
	if (msg != NULL)
		ft_printf("%s", msg);
	exit(error);
}

void	free_error(t_vars, char *msg, int error)
{
	if (vars->mlx != NULL)
		free(vars->mlx);
	if (vars->win != NULL)
		free(vars->win);
	if (vars->img.img != NULL)
		free(vars->img.img);
	if (vars->img.addr != NULL)
		free(vars->img.addr);
	exit_error(msg, error);
}
