/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_event.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 18:41:54 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	mouse_wheel(int mouse_code, t_vars *vars)
{
	if (mouse_code == SCROLL_UP)
	{
		if (vars->camera.zoom > 1)
			vars->camera.zoom -= 1;
	}
	if (mouse_code == SCROLL_DOWN)
	{
		if (vars->camera.zoom < WIN_WIDTH)
			vars->camera.zoom += 1;
	}
	render_window(vars);
	return (0);
}

int	mouse_click(int mouse_code, int x, int y, t_vars *vars)
{
	if (x > MENU_WIDTH)
	{
		vars->camera.mouse_click.x = x;
		vars->camera.mouse_click.y = y;
		if (mouse_code == LEFT_CLICK)
			vars->event.is_left_pressed = true;
		if (mouse_code == RIGHT_CLICK)
			vars->event.is_right_pressed = true;
	}
	return (0);
}

int mouse_pressed(int mouse_code, int x, int y, t_vars *vars)
{
	if (mouse_code == SCROLL_UP || mouse_code == SCROLL_DOWN)
		mouse_wheel(mouse_code, vars);
	if (mouse_code == LEFT_CLICK || mouse_code == RIGHT_CLICK)
		mouse_click(mouse_code, x, y, vars);
	(void)x;
	(void)y;
	return (0);
}

int	mouse_released(int mouse_code, int x, int y, t_vars *vars)
{
	if (mouse_code == LEFT_CLICK)
		vars->event.is_left_pressed = false;
	if (mouse_code == RIGHT_CLICK)
		vars->event.is_right_pressed = false;
	render_window(vars);
	(void)x;
	(void)y;
	return (0);
}

int mouse_move(int x, int y, t_vars *vars)
{
	//if (vars->event.is_left_pressed == true)
	//{
	//	vars->camera.;
	//	vars->camera.;
	//}	
	if (vars->event.is_right_pressed == true)
	{
		vars->camera.mouse_move.x = x;
		vars->camera.mouse_move.y = y;
		render_window(vars);
	}	
	(void)x;
	(void)y;
	return (0);
}
