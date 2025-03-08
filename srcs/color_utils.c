/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 15:58:12 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_color_mode(enum e_mode color_mode, t_vars *vars)
{
	vars->map.color_mode = color_mode;
	if (color_mode == TERRAIN)
		terrain(vars);
	if (color_mode == WHITE_TO_RED)
		white_to_red(vars);
	if (color_mode == BLUE_TO_ORANGE)
		blue_to_orange(vars);
	if (color_mode == WHITE)
		white(vars);
}

int	create_color(int t, int r, int g, int b)
{
	return ((t & 0xFF) << 24 | (r & 0xFF) << 16 | (g & 0xFF) << 8 | (b & 0xFF));
}

float	fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

void	put_inbetween_color(t_point *point, t_color max_color, t_color min_color, t_point z_map)
{
	point->color.r = find_color(max_color.r, min_color.r, z_map, point->z);
	point->color.g = find_color(max_color.g, min_color.g, z_map, point->z);
	point->color.b = find_color(max_color.b, min_color.b, z_map, point->z);
}

void	put_main_colors(t_point *point, t_color color)
{
	point->color.r = color.r;
	point->color.g = color.g;
	point->color.b = color.b;
}
