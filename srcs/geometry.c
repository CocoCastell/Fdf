/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/27 17:12:22 by cochatel         ###   ########.fr       */
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

/*
void	rotate_z(t_point *point, t_camera *camera)
{
	point->x = 
	point->x =
}
*/

void	isometric_projection(t_point *point, t_camera camera)
{
    int	tmp;

	tmp = point->x;
	point->x = (point->x - point->y) * cos(camera.x_angle);
	point->y = (tmp + point->y) * sin(camera.x_angle) - point->z;
}

// Apply the different transformation to a given point
void	apply_changes(t_point *point, t_vars *vars)
{
	t_point map_center;
	
	color_manager(point, vars);
	scale(point, vars->camera);
	if (vars->camera.view_mode == 0)
		isometric_projection(point, vars->camera);
//	if (vars->event.is_left_pressed == true)
//		rotate(point, &vars->camera);
	map_center = new_map_center(vars);
	center(point, map_center, vars);
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
	//ft_printf("AVANT: origin: %d, %d, dest: %d, %d\n", origin.x, origin.y, dest.x, dest.y);
	apply_changes(&origin, vars);
	apply_changes(&dest, vars);
	draw_line(origin, dest, vars);
}
