/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 12:16:45 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

#define CENTER_MENU 50
#define LINE_BREAK 25
#define MAP_INFO_TAB 140
#define COLOR_TAB 320
#define VIEW_TAB 560
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
			if (i < EDGE || j < EDGE || i > MENU_HEIGHT - EDGE || \
					j > MENU_WIDTH - EDGE)
				put_pixel_menu(j, i, &vars->img, MENU_LIMIT);
			else
				put_pixel_menu(j, i, &vars->img, MENU_BACKGD);
		}
	}
}

void	color_mode_str(t_vars *vars)
{
	t_point	coord;
	t_point	width;
	t_point	height;

	width.x = 25;
	width.y = MENU_WIDTH - 25;
	height.x = COLOR_TAB - 25;
	height.y = height.x + 190;
	draw_square(vars, width, height, MENU_LIMIT);
	coord.x = CENTER_MENU;
	coord.y = COLOR_TAB;
	put_str(vars, coord, TITLE_COLOR, "-- CHOSE COLOR --");
	coord.y += LINE_BREAK + 10;
	put_str(vars, coord, TEXT_COLOR, "C/T: Default/Topo mode");
	coord.y += LINE_BREAK + 10;
	put_str(vars, coord, TEXT_COLOR, "1: Terrain");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "2: White to green");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "3: Green to orange");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "4: White");
}

void	view_mode_str(t_vars *vars)
{
	t_point	coord;

	coord.x = CENTER_MENU;
	coord.y = VIEW_TAB;
	put_str(vars, coord, TITLE_COLOR, "-- CONTROLS --");
	coord.y += LINE_BREAK + 10;
	put_str(vars, coord, TEXT_COLOR, "TAB: Isometric/Oblic view");
	coord.y += LINE_BREAK + 10;
	put_str(vars, coord, TEXT_COLOR, "W/S: x axis rotation");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "A/D: y axis rotation");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Q/E: z axis rotation");
	coord.y += LINE_BREAK + 10;
	put_str(vars, coord, TEXT_COLOR, "Translation:");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Left click: permanent");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Right click: temporary");
	coord.y += LINE_BREAK + 10;
	put_str(vars, coord, TEXT_COLOR, "To reset press Space");
}

void	map_info_str(t_vars *vars, t_point coord, int tmp)
{
	char	*str;

	str = ft_itoa(vars->map.x_axis);
	coord.x = CENTER_MENU;
	coord.y = MAP_INFO_TAB;
	put_str(vars, coord, TITLE_COLOR, "- MAP INFO -");
	coord.y += LINE_BREAK + 10;
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
	t_point	coord;
	t_point	width;
	t_point	height;

	coord.x = CENTER_MENU;
	coord.y = LINE_BREAK * 2;
	put_str(vars, coord, TITLE_COLOR, "     MENU   ");
	coord.y += 10;
	put_str(vars, coord, TITLE_COLOR, "______________");
	map_info_str(vars, coord, MENU_WIDTH - 150);
	color_mode_str(vars);
	view_mode_str(vars);
	width.x = 25;
	width.y = MENU_WIDTH - 25;
	height.x = MAP_INFO_TAB - 25;
	height.y = height.x + 130;
	draw_square(vars, width, height, MENU_LIMIT);
	width.x = 25;
	width.y = MENU_WIDTH - 25;
	height.x = VIEW_TAB - 25;
	height.y = height.x + 285;
	draw_square(vars, width, height, MENU_LIMIT);
	coord.y = MENU_HEIGHT - 30;
	put_str(vars, coord, TEXT_COLOR, "Made by @CocoCastell");
}
