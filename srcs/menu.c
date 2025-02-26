/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:14 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	draw_menu(t_vars *vars)
{
	int	i;
	int	j;
	int	color;
	int	win_plane;

	i = -1;
	win_plane = 7;
	while (++i < MENU_HEIGHT)
	{
		j = -1;
		while (++j < MENU_WIDTH)
		{
			if (i < win_plane || j < win_plane || i > MENU_HEIGHT - win_plane || j > MENU_WIDTH - win_plane)
				color = create_color(255, 0, 60, 100);
			else
				color = create_color(255, 111, 111, 111);
			put_pixel(j, i, &vars->img, color);
		}
	}
}

void	put_menu_strings(t_vars *vars)
{
	int	color;

	color = create_color(255, 0, 60, 100);
	mlx_string_put(vars->mlx, vars->win, 125, 50, color, "- MENU -");
}
