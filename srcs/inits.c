/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/03 15:15:27 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	init_map(t_vars *vars)
{
	vars->map.map = NULL;
	vars->map.x_axis = 0;
	vars->map.y_axis = 0;
	vars->map.z_max = 0;
	vars->map.z_min = 0;
	white(vars);
	vars->map.color_mode = WHITE;
}

void	init_event(t_event *event)
{
	event->is_left_pressed = false;
	event->is_right_pressed = false;
	event->is_wheel_pressed = false;
	event->is_1_pressed = false;
	event->is_2_pressed = false;
	event->is_3_pressed = false;
	event->is_3_pressed = false;
	event->has_mouse_moved = false;
	event->is_transposed = false;
	event->is_terrain = false;
}

void	init_camera(t_camera *camera)
{
	camera->zoom = 20;
	camera->x_angle = 0;
	camera->y_angle = 0;
	camera->z_angle = 0;
	camera->mouse_click.x = 0;
	camera->mouse_click.y = 0;
	camera->mouse_move.x = 0;
	camera->mouse_move.y = 0;
	camera->tot_offset.x = 0;
	camera->tot_offset.y = 0;
	camera->view_mode = 0;
	camera->mouse_r_click.x = 0;
	camera->mouse_r_click.y = 0;
	camera->mouse_r_move.x = 0;
	camera->mouse_r_move.y = 0;
	camera->perspective = 1;
}

void	ft_mlx_init(t_vars *vars)
{
	int	x_size;

	x_size = WIN_WIDTH + MENU_WIDTH;
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit_error("Mlx init error\n", 1);
	vars->win = mlx_new_window(vars->mlx, x_size, WIN_HEIGHT, "Rendering");
	if (vars->win == NULL)
		free_error(vars, "Win init error\n", 1);
	vars->img.img = mlx_new_image(vars->mlx, x_size, WIN_HEIGHT);
	if (vars->img.img == NULL)
		free_error(vars, "Img init error\n", 1);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		free_error(vars, "Img addr init error\n", 1);
	init_camera(&vars->camera);
	init_map(vars);
	init_event(&vars->event);
	(void)vars;
}
