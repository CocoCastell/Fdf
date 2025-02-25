/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 15:30:47 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	blue_to_orange(t_vars *vars)
{
	vars->map.max_color.r = 240;
	vars->map.max_color.g = 248;
	vars->map.max_color.b = 255;
	vars->map.min_color.r = 255;
	vars->map.min_color.g = 36;
	vars->map.min_color.b = 0;
}
