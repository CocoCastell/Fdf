/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 16:24:47 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	find_color(int max_color, int min_color, t_point z_map, int height)
{
	int		color;
	double	coef;

	coef = 0;
	if (z_map.x != z_map.y)
		coef = fraction((float)z_map.y, (float)z_map.x, (float)height);
	if (coef < 0)
		coef = 0;
	if (coef > 1)
		coef = 1;
	color = coef * (max_color - min_color) + min_color;
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}

/*void	gradient_terrain_mode(t_point *point, t_map *map, t_point z_map)
{
	t_point z_map;

	z_map.x = LOW;
	z_map.y = vars->map.z_min;
	if (point->z <= VERY_LOW)
		put_main_colors(point, map->very_low_color);
	else if (point->z <= LOW)
		inbetween_col(point, map->low_color, map->very_low_color, z_map);
	else if (point->z <= MIDDLE)
	{
		z_map.x = MIDDLE;
		z_map.y = LOW;
		inbetween_col(point, map->hight_color, map->mid_color, z_map);
	}
	else if (point->z <= HIGHT)
	{
		z_map.x = HIGHT;
		z_map.y = MIDDLE;
		inbetween_col(point, map->very_hight_color, map->hight_color, z_map);
	}
	else if (point->z <= VERY_HIGHT)
	{
		z_map.x = map->z_max;
		z_map.y = HIGHT;
		inbetween_col(point, map->very_hight_color, map->hight_color, z_map);
	}
	else
		put_main_colors(point, map->very_hight_color);
}*/

void	gradient_terrain_mode(t_point *point, t_map *map)
{
	if (point->z <= VERY_LOW)
		put_main_colors(point, map->very_low_color);
	else if (point->z <= LOW)
		put_main_colors(point, map->low_color);
	else if (point->z <= MIDDLE)
		put_main_colors(point, map->mid_color);
	else if (point->z <= HIGHT)
		put_main_colors(point, map->hight_color);
	else
		put_main_colors(point, map->very_hight_color);
}

void	gradient_color_mode(t_point *point, t_map *map)
{
	int		limit;
	t_point	z_map;

	limit = (map->z_max - map->z_min) / 2;
	if (point->z == map->z_max)
		put_main_colors(point, map->hight_color);
	else if (point->z == limit)
		put_main_colors(point, map->mid_color);
	else if (point->z == map->z_min && limit != map->z_min)
		put_main_colors(point, map->low_color);
	else if (point->z > limit)
	{
		z_map.x = map->z_max;
		z_map.y = map->z_max / 2;
		inbetween_col(point, map->hight_color, map->mid_color, z_map);
	}
	else
	{
		z_map.x = map->z_max / 2;
		z_map.y = map->z_min;
		inbetween_col(point, map->mid_color, map->low_color, z_map);
	}
}

float	interpolation_fraction(t_point origin, t_point dest, t_point pixel)
{
	float	coef;
	t_point	diff;

	diff.y = (dest.y - origin.y);
	diff.x = (dest.x - origin.x);
	if (abs(diff.x) > abs(diff.y))
		coef = fraction(origin.x, dest.x, pixel.x);
	else
		coef = (fraction(origin.y, dest.y, pixel.y));
	return (coef);
}

int	set_pix_color(t_point origin, t_point dest, t_point pix)
{
	int		pix_color;
	float	f;

	f = interpolation_fraction(origin, dest, pix);
	pix.color.r = origin.color.r + (dest.color.r - origin.color.r) * f;
	pix.color.g = origin.color.g + (dest.color.g - origin.color.g) * f;
	pix.color.b = origin.color.b + (dest.color.b - origin.color.b) * f;
	pix_color = create_color(255, pix.color.r, pix.color.g, pix.color.b);
	return (pix_color);
}
