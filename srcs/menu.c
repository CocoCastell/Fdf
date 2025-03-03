/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/27 13:06:39 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define CENTER_MENU 70
#define LINE_BREAK 30
#define MAP_INFO_TAB 150
#define COLOR_TAB 375
#define VIEW_TAB 600
#define LINE 20
#define EDGE 2

void	draw_background(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MENU_HEIGHT)
	{
		j = -1;
		while (++j < MENU_WIDTH)
		{
			if (i < EDGE|| j < EDGE || i > MENU_HEIGHT - EDGE || j > MENU_WIDTH - EDGE)
				put_pixel_menu(j, i, &vars->img, MENU_LIMIT);
			else
				put_pixel_menu(j, i, &vars->img, MENU_BACKGD);
		}
	}
}

void	color_mode_str(t_vars *vars)
{
	t_point coord;
	t_point width;
	t_point	height;
	
	width.x = 25;
	width.y = MENU_WIDTH - 25;
	height.x = COLOR_TAB - 25;
	height.y = height.x + 165;
	draw_square(vars, width, height, MENU_LIMIT);
	coord.x = CENTER_MENU;
	coord.y = COLOR_TAB;
	put_str(vars, coord, TITLE_COLOR, "-- CHOSE COLOR --");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "1: Terrain");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "2: White to red");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "3: Green to orange");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "4: White");

}

void	view_mode_str(t_vars *vars)
{
	t_point coord;

	coord.x = CENTER_MENU;
	coord.y = VIEW_TAB;
	put_str(vars, coord, TITLE_COLOR, "-- CHOSE VIEW --");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Isometric: press TAB ");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "AUTRE: press ?? ");
	coord.y += LINE_BREAK;
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "To reset press Space");
}

void	map_info_str(t_vars *vars)
{
	t_point coord;
	char	*str;
	int tmp;

	tmp = MENU_WIDTH - 150;
	str = ft_itoa(vars->map.x_axis);
	coord.x = CENTER_MENU;
	coord.y = MAP_INFO_TAB;
	put_str(vars, coord, TITLE_COLOR, "- MAP INFO -");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map width: ");
	coord.x += tmp;
	put_str(vars, coord, TEXT_COLOR, str);
	coord.x -= tmp;
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map length: ");
	free(str);
	str = ft_itoa(vars->map.y_axis);
	coord.x += tmp;
	put_str(vars, coord, TEXT_COLOR, str);
	coord.x -= tmp;
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map max height: ");
	free(str);
	str = ft_itoa(vars->map.z_max);
	coord.x += tmp;
	put_str(vars, coord, TEXT_COLOR, str);
	free(str);
}

void	draw_menu(t_vars *vars)
{
	t_point coord;
	t_point	width;
	t_point height;

	coord.x = CENTER_MENU;
	coord.y = LINE_BREAK * 2;
	put_str(vars, coord, TITLE_COLOR, "     MENU   ");
	coord.y += 10;
	put_str(vars, coord, TITLE_COLOR, "______________");
	map_info_str(vars);
	color_mode_str(vars);
	view_mode_str(vars);
	width.x = 25;
	width.y = MENU_WIDTH - 25;
	height.x = MAP_INFO_TAB - 25;
	height.y = height.x + 145;
	draw_square(vars, width, height, MENU_LIMIT);
	width.x = 25;
	width.y = MENU_WIDTH - 25;
	height.x = VIEW_TAB - 25;
	height.y = height.x + 165;
	draw_square(vars, width, height, MENU_LIMIT);
	coord.y = MENU_HEIGHT - 30;
	put_str(vars, coord, TEXT_COLOR,"Made by @CocoCastell");
}
