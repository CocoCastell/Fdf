/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/27 18:07:27 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int	find_color(int max_color, int min_color, t_point z_map, t_vars *vars, int height)
{
	int	color;
	double coef;

	(void)vars;
	coef = 0;
	if (z_map.x != z_map.y)
		coef = fraction((float)z_map.y, (float)z_map.x, (float)height);
	//if (vars->map.z_max != vars->map.z_min)
	//	coef = fraction((float)vars->map.z_min, (float)vars->map.z_max, (float)height);
	color = coef * (max_color - min_color) + min_color; 
	//if (height < (vars->map.z_min - vars->map.z_min) / 2)
	//		color = coef * (mid_color - min_color) + min_color; 
	//else
	//		color = coef * (max_color - mid_color) + min_color; 
	if (color > 255)
		color = 255;
	if (color < 0)
		color = 0;
	return (color);
}

void	color_manager(t_point *point, t_vars *vars)
{
	int	h;
	int	limit;
	t_point z_map;
	
	h = point->z;
	limit = (vars->map.z_max - vars->map.z_min) / 2;
	if (vars->map.color_mode == TERRAIN)
		limit = 0;
	if (point->z == vars->map.z_max)
	{
		point->color.r = vars->map.max_color.r;
		point->color.g = vars->map.max_color.g;
		point->color.b = vars->map.max_color.b;
	}
	else if (point->z == limit)
	{
		point->color.r = vars->map.mid_color.r;
		point->color.g = vars->map.mid_color.g;
		point->color.b = vars->map.mid_color.b;
	}
	else if (point->z == vars->map.z_min && (limit != vars->map.z_min && vars->map.color_mode == TERRAIN))
	{
		point->color.r = vars->map.min_color.r;
		point->color.g = vars->map.min_color.g;
		point->color.b = vars->map.min_color.b;
	}
	else if (point->z > limit)
	{
		//z_map.x = vars->map.z_max;
		//z_map.y = limit;
		z_map.x = vars->map.z_max;
		z_map.y = vars->map.z_max / 2;
		point->color.r = find_color(vars->map.max_color.r, vars->map.mid_color.r, z_map, vars, h);
		point->color.g = find_color(vars->map.max_color.g, vars->map.mid_color.g, z_map, vars, h);
		point->color.b = find_color(vars->map.max_color.b, vars->map.mid_color.b, z_map, vars, h);
	}
	else
	{
		z_map.x = vars->map.z_max / 2;
		z_map.y = vars->map.z_min;
		//z_map.x = limit;
	//	z_map.y = vars->map.z_min;
		point->color.r = find_color(vars->map.mid_color.r, vars->map.min_color.r, z_map, vars, h);
		point->color.g = find_color(vars->map.mid_color.g, vars->map.min_color.g, z_map, vars, h);
		point->color.b = find_color(vars->map.mid_color.b, vars->map.min_color.b, z_map, vars, h);
	}
}

/*void	color_manager(t_point *point, t_vars *vars)
{
	int	h;
	t_point z_map;
	
	h = (point->z - vars->map.z_min);
	//ft_printf("H poin: %d, diff: %d, map min %d, map max: %d\n", h, y, vars->map.z_min, vars->map.z_max);
	if (h > (vars->map.z_max - vars->map.z_min) / 2)
	{
		z_map.x = vars->map.z_max;
		z_map.y = vars->map.z_max / 2;
		point->color.r = find_color(vars->map.max_color.r, vars->map.mid_color.r, z_map, vars, h);
		point->color.g = find_color(vars->map.max_color.g, vars->map.mid_color.g, z_map, vars, h);
		point->color.b = find_color(vars->map.max_color.b, vars->map.mid_color.b, z_map, vars, h);
	}
	else
	{
		z_map.x = vars->map.z_max / 2;
		z_map.y = vars->map.z_min;
		point->color.r = find_color(vars->map.mid_color.r, vars->map.min_color.r, z_map, vars, h);
		point->color.g = find_color(vars->map.mid_color.g, vars->map.min_color.g, z_map, vars, h);
		point->color.b = find_color(vars->map.mid_color.b, vars->map.min_color.b, z_map, vars, h);
	}
	//ft_printf("r: %d, g: %d, b: %d\n", point->color.r, point->color.g, point->color.b);
}*/

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

int	set_pix_color(t_point origin, t_point dest, t_point pix, t_vars *vars)
{
	int pix_color;
	float	f;
	
	(void)vars;
	f = interpolation_fraction(origin, dest, pix);
	pix.color.r = origin.color.r + (dest.color.r - origin.color.r) * f;
	pix.color.g = origin.color.g + (dest.color.g - origin.color.g) * f;
	pix.color.b = origin.color.b + (dest.color.b - origin.color.b) * f;
	pix_color = create_color(255, pix.color.r, pix.color.g, pix.color.b);
	return (pix_color);
}
