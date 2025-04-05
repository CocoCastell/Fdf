/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 12:18:26 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

// To find the center on the map after transformation
t_point	new_map_center(t_vars *vars)
{
	t_point	center;

	center.x = vars->map.x_axis / 2;
	center.y = vars->map.y_axis / 2;
	center.z = (vars->map.z_max - vars->map.z_min) / 2;
	center.y *= vars->camera.zoom;
	center.x *= vars->camera.zoom;
	center.z *= vars->camera.zoom;
	isometric_projection(&center);
	return (center);
}

// To display strings on the window
void	put_str(t_vars *vars, t_point coord, int color, char *text)
{
	mlx_string_put(vars->mlx, vars->win, coord.x, coord.y, color, text);
}

// Draw the pixel of the menu
void	put_pixel_menu(int x, int y, t_data_img *img, int color)
{
	char	*dst;

	if (x <= MENU_WIDTH && x >= 0 && y <= WIN_HEIGHT && y >= 0)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

// Draw squares for the menu
void	draw_square(t_vars *vars, t_point width, t_point height, int color)
{
	int	w;
	int	h;
	int	l;

	l = 1;
	h = height.x;
	w = width.x;
	while (height.x < height.y)
	{
		width.x = w;
		while (width.x < width.y)
		{
			if (!(height.x >= (h + l) && height.x < (height.y - l) && \
						width.x >= (w + l) && width.x < (width.y - l)))
				put_pixel_menu(width.x, height.x, &vars->img, color);
			width.x++;
		}
		height.x++;
	}
}
