/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/27 18:08:43 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	white_to_red(t_vars *vars)
{
	vars->map.very_low_color.r = 200;
	vars->map.very_low_color.g = 220;
	vars->map.very_low_color.b = 255;
	vars->map.low_color.r = 200;
	vars->map.low_color.g = 220;
	vars->map.low_color.b = 255;
	vars->map.mid_color.r = 156;
	vars->map.mid_color.g = 39;
	vars->map.mid_color.b = 189;
	vars->map.hight_color.r = 0;
	vars->map.hight_color.g = 255;
	vars->map.hight_color.b = 77;
	vars->map.very_hight_color.r = 228;
	vars->map.very_hight_color.g = 223;
	vars->map.very_hight_color.b = 81;
}

void	blue_to_orange(t_vars *vars)
{
	vars->map.very_low_color.r = 103;
	vars->map.very_low_color.g = 175;
	vars->map.very_low_color.b = 238;
	vars->map.low_color.r = 10;
	vars->map.low_color.g = 186;
	vars->map.low_color.b = 181;
	vars->map.mid_color.r = 63;
	vars->map.mid_color.g = 236;
	vars->map.mid_color.b = 230;
	vars->map.hight_color.r = 236;
	vars->map.hight_color.g = 194;
	vars->map.hight_color.b = 80;
	vars->map.very_hight_color.r = 233;
	vars->map.very_hight_color.g = 39;
	vars->map.very_hight_color.b = 39;
}

void	white(t_vars *vars)
{
	vars->map.very_low_color.r = 255;
	vars->map.very_low_color.g = 255;
	vars->map.very_low_color.b = 255;
	vars->map.low_color.r = 255;
	vars->map.low_color.g = 255;
	vars->map.low_color.b = 255;
	vars->map.mid_color.r = 176;
	vars->map.mid_color.g = 176;
	vars->map.mid_color.b = 176;
	vars->map.hight_color.r = 184;
	vars->map.hight_color.g = 223;
	vars->map.hight_color.b = 214;
	vars->map.very_hight_color.r = 184;
	vars->map.very_hight_color.g = 223;
	vars->map.very_hight_color.b = 214;
}

void	terrain(t_vars *vars)
{
	vars->map.very_low_color.r = 31;
	vars->map.very_low_color.g = 104;
	vars->map.very_low_color.b = 141;
	vars->map.low_color.r = 38;
	vars->map.low_color.g = 160;
	vars->map.low_color.b = 220;
	vars->map.mid_color.r = 67;
	vars->map.mid_color.g = 225;
	vars->map.mid_color.b = 124;
	vars->map.hight_color.r = 178;
	vars->map.hight_color.g = 146;
	vars->map.hight_color.b = 58;
	vars->map.very_hight_color.r = 240;
	vars->map.very_hight_color.g = 240;
	vars->map.very_hight_color.b = 240;
}
