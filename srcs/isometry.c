/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isometry.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 16:21:40 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    center(t_point *point, t_point map_center)
{
	point->x += (WIN_WIDTH / 2) - map_center.x + MENU_WIDTH;
	point->y += (WIN_HEIGHT / 2) - map_center.y;
}

void	scale(t_point *point, t_camera camera)
{
	point->x *= camera.zoom;
	point->y *= camera.zoom;
	point->z *= camera.zoom;
}

void	isometric_projection(t_point *point, t_camera camera)
{
    int	tmp;

	tmp = point->x;
	point->x = (point->x - point->y) * cos(camera.x_angle);
	point->y = (tmp + point->y) * sin(camera.x_angle) - point->z;
}

void    isometric_view(t_point origin, t_point dest, t_vars *vars)
{
        t_point map_center;

	set_point_color(&origin, vars);
        set_point_color(&dest, vars);
	//	ft_printf("AVANT: origin: %d, %d, dest: %d, %d\n", origin.x, origin.y, dest.x, dest.y);
	//ft_printf("color o: %d, color d: %d\n", origin.color.r, dest.color.r);
	scale(&origin, vars->camera);
        scale(&dest, vars->camera);
        isometric_projection(&origin, vars->camera);
        isometric_projection(&dest, vars->camera);
        map_center = new_map_center(vars);
        center(&origin, map_center);
        center(&dest, map_center);
        draw_line(origin, dest, vars);
}
