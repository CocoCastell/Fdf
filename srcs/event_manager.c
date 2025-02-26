/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 10:58:41 by cochatel         ###   ########.fr       */
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
			vars->camera.zoom -= 1;
	}
	if (mousecode == MOUSE_WHEEL_DOWN)
	{
		if (vars->camera.zoom < WIN_WIDTH)
			vars->camera.zoom += 1;
	}
	render_window(vars);
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
	mlx_hook(vars->win, ClientMessage, StructureNotifyMask, my_close, vars);
	mlx_key_hook(vars->win, handle_key, vars);
	mlx_hook(vars->win, 4, 1L << 2, handle_mouse, vars);
	(void)vars;
}
