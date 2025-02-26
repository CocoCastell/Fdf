/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 16:12:36 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	white_to_red(t_vars *vars)
{
	vars->map.min_color.r = 200;
	vars->map.min_color.g = 220;
	vars->map.min_color.b = 255;
	vars->map.max_color.r = 255;
	vars->map.max_color.g = 80;
	vars->map.max_color.b = 0;
}

void	blue_to_orange(t_vars *vars)
{
	vars->map.min_color.r = 10;
	vars->map.min_color.g = 186;
	vars->map.min_color.b = 181;
	vars->map.max_color.r = 255;
	vars->map.max_color.g = 127;
	vars->map.max_color.b = 0;
}

void	white(t_vars *vars)
{
	vars->map.min_color.r = 255;
	vars->map.min_color.g = 255;
	vars->map.min_color.b = 255;
	vars->map.max_color.r = 255;
	vars->map.max_color.g = 255;
	vars->map.max_color.b = 255;
}

void	terrain(t_vars *vars)
{
	vars->map.min_color.r = 49;
	vars->map.min_color.g = 140;
	vars->map.min_color.b = 231;
	vars->map.max_color.r = 84;
	vars->map.max_color.g = 248;
	vars->map.max_color.b = 90;
}
