/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/03 17:16:41 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// Translate the point -> it would be better to put the coordinates in a matrix ?
// We divide by 2 the offset in case the function is called twice
void	transpose(t_point *point, t_camera *camera, t_event event)
{
	t_point	diff;

	if (event.is_transposed == true && event.is_right_pressed == false)
	{
		diff.x = camera->tot_offset.x;
		diff.y = camera->tot_offset.y;
	}
	else
	{
		diff.x = camera->mouse_r_move.x - camera->mouse_r_click.x + (camera->tot_offset.x / 2);
		diff.y = camera->mouse_r_move.y - camera->mouse_r_click.y + (camera->tot_offset.y / 2);
	}
	point->x += diff.x;
	point->y += diff.y;
}

void	isometric_projection(t_point *point)
{
	int	tmp;

	tmp = point->x;
	point->x = (point->x - point->y) * cos(0.5236);
	point->y = (tmp + point->y) * sin(0.5236) - point->z;
}

//Effet de voyage supraluminique:
// if (point->z != 0)
// point->x = (point->x * 10) / point->z;
// point->y = (point->y * 10) / point->z;
/*void	perspective_projection(t_point *point)
{
	if (point->z > 0.001)
	{
		point->x = point->x / point->z;
		point->y = -(point->y / point->z);
	}
}*/

void	oblic_projection(t_point *point)
{
	float	angle;

	angle = M_PI / 4;
	point->x = point->x + 0.5 * point->z * cos(angle);  
	point->y = point->y + 0.5 * point->z * sin(angle);
}

// Apply the different transformation to a given point
// Recenter the point for the rotation to apply at center
void	apply_changes(t_point *point, t_vars *vars)
{
	if (vars->event.is_terrain == false)
		gradient_color_mode(point, vars);
	else
		gradient_terrain_mode(point, vars);
	scale(point, vars->camera);
	point->x -= vars->map.x_axis * vars->camera.zoom / 2;
	point->y -= vars->map.y_axis * vars->camera.zoom / 2;
	rotate_z(point, vars->camera);
	rotate_x(point, vars->camera);
	rotate_y(point, vars->camera);
	if (vars->camera.view_mode == 0)
		isometric_projection(point);
	else
		oblic_projection(point);
	center(point);
	if (vars->event.has_mouse_moved == true || vars->event.is_transposed == true)
	{
		vars->event.is_transposed = true;
		transpose(point, &vars->camera, vars->event);
	}
	if (vars->event.is_right_pressed == true)
		transpose(point, &vars->camera, vars->event);
}

void    apply_changes_and_draw(t_point origin, t_point dest, t_vars *vars)
{
	apply_changes(&origin, vars);
	apply_changes(&dest, vars);
	draw_line(origin, dest, vars);
}
