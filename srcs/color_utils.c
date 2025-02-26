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

float fraction(float x1, float x2, float x)
{
	if (x1 != x2)
		return ((x - x1) / (x2 - x1));
	return (0);
}

