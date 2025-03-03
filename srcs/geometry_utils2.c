/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/03 13:57:38 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate_z(t_point *point, t_camera camera)
{
	int	tmp;
	
	tmp = point->x;
	point->x = tmp * cos(camera.z_angle) - point->y * sin(camera.z_angle);
	point->y = tmp * sin(camera.z_angle) + point->y * cos(camera.z_angle);
}

void	rotate_y(t_point *point, t_camera camera)
{
	int	tmp;

	tmp = point->x;
	point->x = tmp * cos(camera.y_angle) + point->z * sin(camera.y_angle);
	point->z = -tmp * sin(camera.y_angle) + point->z * cos(camera.y_angle);
}

void	rotate_x(t_point *point, t_camera camera)
{
	int	tmp;

	tmp = point->y;
	point->y = tmp * cos(camera.x_angle) - point->z * sin(camera.x_angle);
	point->z = tmp * sin(camera.x_angle) + point->z * cos(camera.x_angle);
}

void	center_rotation(t_point *point)
{
	point->x -= map.x_axis * camera.zoom / 2;
	point->y -= map.y_axis * camera.zoom / 2;
}
