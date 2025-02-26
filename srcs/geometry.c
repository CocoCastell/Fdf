/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 18:54:11 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	transpose(t_point *point, t_camera camera)
{
	t_point	diff;
	
	diff.x = camera.mouse_click.x - camera.mouse_move.x;
	diff.y = camera.mouse_click.y - camera.mouse_move.y;
	diff.x = -diff.x;
	diff.y = -diff.y;
	point->x += diff.x;
	point->y += diff.y;
}

/*
void	rotate(t_vars *vars)
{
	update_coordinates();
}
*/
void	isometric_projection(t_point *point, t_camera camera)
{
    int	tmp;

	tmp = point->x;
	point->x = (point->x - point->y) * cos(camera.x_angle);
	point->y = (tmp + point->y) * sin(camera.x_angle) - point->z;
}

void	apply_changes(t_point *point, t_vars *vars)
{
	t_point map_center;
	
	set_point_color(point, vars);
	scale(point, vars->camera);
	if (vars->camera.view_mode == 0)
		isometric_projection(point, vars->camera);
	if (vars->event.is_right_pressed == true)
		transpose(point, vars->camera);
	//if (vars->event.is_left_pressed== true)
	//	rotate(vars->camera, &origin);
	map_center = new_map_center(vars);
	center(point, map_center);
}

void    apply_changes_and_draw(t_point origin, t_point dest, t_vars *vars)
{
	//ft_printf("AVANT: origin: %d, %d, dest: %d, %d\n", origin.x, origin.y, dest.x, dest.y);
	//ft_printf("color o: %d, color d: %d\n", origin.color.r, dest.color.r);
	apply_changes(&origin, vars);
	apply_changes(&dest, vars);
	draw_line(origin, dest, vars);
}
