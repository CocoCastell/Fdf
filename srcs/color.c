/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 17:45:55 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	create_color(int t, int r, int g, int b)
{
	return ((t & 0xFF) << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
}

int	find_color(int max_color, int min_color, t_vars *vars, int height_point)
{
	int	color;
	float coef;
	t_point diff;

	diff.y = (vars->map.z_min - vars->map.z_max) * vars->camera.zoom;
	diff.x = max_color - min_color;
	if (diff.x != 0)
		coef = diff.y / diff.x;
	color = coef * (height_point) + min_color;
	return (color);
}

void	set_point_color(t_point *point, t_vars *vars)
{
	int	h;

	h = (point->z - vars->map.z_min) * vars->camera.zoom;
	point->color.r = find_color(vars->map.max_color.r, vars->map.max_color.r, vars, h);
	point->color.g = find_color(vars->map.max_color.g, vars->map.max_color.g, vars, h);
	point->color.b = find_color(vars->map.max_color.b, vars->map.max_color.b, vars, h);
}

float progression_fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

int	find_fraction(t_point origin, t_point dest, t_point pixel, t_vars *vars)
{
	float coef;
	t_point diff;

	diff.y = dest.y - origin.y * vars->camera.zoom;
	diff.x = dest.x - origin.x * vars->camera.zoom;
	if (abs(diff.x) > abs(diff.y))
		coef = progression_fraction(origin.x, dest.x, pixel.x);
	return (coef);
	//color = coef * (height_point) + min_color;
}

int	set_pixel_color(t_point origin, t_point dest, t_point pixel, t_vars *vars)
{
	int pixel_color;
	float	f;
	
	f = find_fraction(origin, dest, pixel, vars);
	pixel.color.r = origin.color.r + (dest.color.r - origin.color.r) * f;
	pixel.color.g = origin.color.g + (dest.color.g - origin.color.g) * f;
	pixel.color.b = origin.color.b + (dest.color.b - origin.color.b) * f;
	pixel_color = create_color(255, pixel.color.r, pixel.color.g, pixel.color.b);
	return (pixel_color);
}
