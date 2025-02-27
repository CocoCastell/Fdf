/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/27 13:13:04 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	exit_error(char *msg, int error)
{
	if (msg != NULL)
		ft_printf("%s", msg);
	exit(error);
}

void	free_error(t_vars *vars, char *msg, int error)
{
	if (vars->map.map != NULL)
		ft_free_matrix(vars->map.map, vars->map.y_axis);
	if (vars->img.img != NULL)
		mlx_destroy_image(vars->mlx, vars->img.img);
	if (vars->win != NULL)
		mlx_destroy_window(vars->mlx, vars->win);
	if (vars->mlx != NULL)
	{
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	exit_error(msg, error);
}

void	error_map(char *str1, char *str2, t_vars *vars, char *msg)
{
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	free_error(vars, msg, 1);
}
