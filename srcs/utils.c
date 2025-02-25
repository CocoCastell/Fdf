/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:14 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	new_map_center(t_vars *vars)
{
	t_point center;

	center.x = vars->map.x_axis / 2;
	center.y = vars->map.y_axis / 2;
	center.z = vars->map.z_max - vars->map.z_min;
	if (center.z < 20 && center.z > -20)
		center.z = 0;
	isometric_projection(&center, vars->camera);
	center.y *= vars->camera.zoom;
	center.x *= vars->camera.zoom;
	return (center);
}
