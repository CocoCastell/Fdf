/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_interaction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:47:58 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	handle_mouse(int mousecode, int x, int y, t_vars *vars)
{
	(void)x;
	(void)y;
	if (mousecode == MOUSE_WHEEL_UP)
	{
		if (vars->camera.zoom > 1)
			vars->camera.zoom--;
		//ft_printf("Zoom: %d\n", vars->camera.zoom);
	}
	if (mousecode == MOUSE_WHEEL_DOWN)
	{
		if (vars->camera.zoom < WIN_WIDTH)
			vars->camera.zoom++;
	}
	//mlx_clear_window(vars->mlx, vars->win);
	//rendering_map(vars);
	//mlx_put_image_to_window(vars->mlx, vars->win, vars->    img.img, 0, 0);
	return (0);
}

int	handle_key(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		my_close(vars);
	return (0);
}

void    event_manager(t_vars *vars)
{
	//ft_printf("Zoom: %d\n", vars->camera.zoom);
        ft_printf("window_manager: vars addr = %p\n", vars);
	mlx_hook(vars->win, ClientMessage, StructureNotifyMask, my_close, vars);
	mlx_key_hook(vars->win, handle_key, vars);
	mlx_hook(vars->win, 4, 1L << 2, handle_mouse, vars);
	(void)vars;
}
