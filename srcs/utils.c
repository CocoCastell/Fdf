/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:45:31 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_point	new_map_center(t_vars *vars)
{
        t_point center;

        center.x = vars->map.x_axis / 2;
        center.y = vars->map.y_axis / 2;
        center.z = 0;
        isometric_projection(&center, vars->camera);
        center.y *= vars->camera.zoom;
        center.x *= vars->camera.zoom;
	return (center);
}

int	find_offset(t_map map, t_camera camera)
{
	t_point offset;
	int	diff;
	
	diff = 0;
	offset.x = 1;
	offset.y = map.y_axis;
	scale(&offset, camera);
	isometric_projection(&offset, camera);
	ft_printf("offset x: %d, y: %d\n", offset.x, offset.y);
	/*offset.x = map.x_axis;
	offset.y = 1;
	scale(&offset, camera);
	isometric_projection(&offset, camera);
	ft_printf("offset x: %d, y: %d\n", offset.x, offset.y);
	*/
	if (offset.x < 0)
		diff = offset.y + offset.x;
	return (diff);
}
