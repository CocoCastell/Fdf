/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometry_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/27 14:36:35 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    center(t_point *point, t_point map_center, t_vars *vars)
{
	(void)vars;

	point->x += ((WIN_WIDTH + MENU_WIDTH ) / 2) - map_center.x + MENU_WIDTH / 2;	
	point->y += (WIN_HEIGHT / 2) - map_center.y;
}

void	scale(t_point *point, t_camera camera)
{
	point->x *= camera.zoom;
	point->y *= camera.zoom;
	point->z *= camera.zoom;
}

