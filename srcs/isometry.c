/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:47:58 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    center(t_point *point, t_point map_center)
{

	point->x += (WIN_WIDTH / 2) - map_center.x;
	point->y += (WIN_HEIGHT / 2) - map_center.y;
	//int y = find_offset(vars->map, vars->camera);
	//ft_printf("y: %d\n", y);
}

void	scale(t_point *point, t_camera camera)
{
	point->x *= camera.zoom;
	point->y *= camera.zoom;
	point->z *= camera.zoom;
}

void	isometric_projection(t_point *point, t_camera camera)
{
        int     tmp;

	tmp = point->x;
	point->x = (point->x - point->y) * cos(camera.x_angle);
	point->y = (tmp + point->y) * sin(camera.x_angle) - point->z;
}

void    isometric_view(t_point origin, t_point dest, t_vars *vars)
{
        t_point map_center;

	//ft_printf("AVANT: origin: %d, %d, dest: %d, %d\n", origin.x, origin.y, dest.x, dest.y);
        scale(&origin, vars->camera);
        scale(&dest, vars->camera);
        isometric_projection(&origin, vars->camera);
        isometric_projection(&dest, vars->camera);
        map_center = new_map_center(vars);
        //ft_printf("center: (%d, %d)\n", map_center.x, map_center.y);
        center(&origin, map_center);
        center(&dest, map_center);
        draw_line(origin, dest, vars);
}
