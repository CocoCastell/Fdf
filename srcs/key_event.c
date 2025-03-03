/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/03 15:19:15 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_close(t_vars *vars)
{
	free_mlx(vars);
	exit(0);
}

void	init_offset(t_vars *vars)
{
	vars->event.is_transposed = false;
	vars->camera.tot_offset.x = 0;
	vars->camera.tot_offset.y = 0;
	vars->camera.x_angle = 0;
	vars->camera.y_angle = 0;
	vars->camera.z_angle = 0;
}

void	increase_angle(t_camera *camera, int keycode)
{
	if (keycode == W)
		camera->x_angle += 0.05;
	if (keycode == D)
		camera->y_angle += 0.05;
	if (keycode == E)
		camera->z_angle += 0.05;
}

void	decrease_angle(t_camera *camera, int keycode)
{
	if (keycode == S)
		camera->x_angle -= 0.05;
	if (keycode == A)
		camera->y_angle -= 0.05;
	if (keycode == Q)
		camera->z_angle -= 0.05;
}

int	key_pressed(int keycode, t_vars *vars)
{
	if (keycode == KEY_1)
		put_color_mode(TERRAIN, vars);
	if (keycode == KEY_2)
		put_color_mode(WHITE_TO_RED, vars);
	if (keycode == KEY_3)
		put_color_mode(BLUE_TO_ORANGE, vars);
	if (keycode == KEY_4)
		put_color_mode(WHITE, vars);
	if (keycode == ESC)
		my_close(vars);
	if (keycode == SPACE)
		init_offset(vars);
	if (keycode == W || keycode == D || keycode == E)
		increase_angle(&vars->camera, keycode);
	if (keycode == S || keycode == A || keycode == Q)
		decrease_angle(&vars->camera, keycode);
	if (keycode == TAB)
	{
		if (vars->camera.view_mode == 0)
			vars->camera.view_mode = 1;
		else
			vars->camera.view_mode = 0;
	}
	render_window(vars);
	return (0);
}
