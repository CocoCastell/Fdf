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

float fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

int	find_color(int max_color, int min_color, t_vars *vars, int height_point)
{
	int	color;
	double coef;
	//double dy;
	//double dx;

	coef = 0;
	//dy = (vars->map.z_max - vars->map.z_min);// * vars->camera.zoom;
	//dx = (max_color - min_color);
	//ft_printf("APRES: diff.x: %d, diff.y: %d\n", diff.x, diff.y);
	//if (abs(diff.x) > abs(diff.y))
	//	coef = progression_fraction(origin.x, dest.x, pixel.x);
	//else
	//	coef = progression_fraction(origin.y, dest.y, pixel.y);
	if (vars->map.z_max != vars->map.z_min)
		coef = fraction((float)vars->map.z_min, (float)vars->map.z_max, (float)height_point);
	color = coef * (max_color - min_color) + min_color; 
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}

void	set_point_color(t_point *point, t_vars *vars)
{
	int	h;

	h = (point->z - vars->map.z_min);// * vars->camera.zoom;
	point->color.r = find_color(vars->map.max_color.r, vars->map.min_color.r, vars, h);
	point->color.g = find_color(vars->map.max_color.g, vars->map.min_color.g, vars, h);
	point->color.b = find_color(vars->map.max_color.b, vars->map.min_color.b, vars, h);
	//ft_printf("r: %d, g: %d, b: %d\n", point->color.r, point->color.g, point->color.b);
}

float	interpolation_fraction(t_point origin, t_point dest, t_point pixel)
{
	float coef;
	t_point diff;

	diff.y = (dest.y - origin.y);
	diff.x = (dest.x - origin.x);
	if (abs(diff.x) > abs(diff.y))
		coef = fraction(origin.x, dest.x, pixel.x);
	else
		coef = (fraction(origin.y, dest.y, pixel.y));
	return (coef);
}

int	set_pixel_color(t_point origin, t_point dest, t_point pixel, t_vars *vars)
{
	int pixel_color;
	float	f;
	
	(void)vars;
	//ft_printf("ox: %d, oy: %d, dx: %d, dy: %d, pix: %d, piy: %d\n", origin.x, origin.y, dest.x, dest.y, pixel.x, pixel.y);
	f = interpolation_fraction(origin, dest, pixel);
	pixel.color.r = origin.color.r + (dest.color.r - origin.color.r) * f;
	pixel.color.g = origin.color.g + (dest.color.g - origin.color.g) * f;
	pixel.color.b = origin.color.b + (dest.color.b - origin.color.b) * f;
	pixel_color = create_color(255, pixel.color.r, pixel.color.g, pixel.color.b);
	return (pixel_color);
}
