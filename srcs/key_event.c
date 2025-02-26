/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 19:19:11 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
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
	render_window(vars);
	return (0);
}

/*int	key_released(int keycode, t_vars *vars)
{
	return (0);
}
*/
