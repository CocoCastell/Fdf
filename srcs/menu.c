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

#define CENTER_MENU (MENU_WIDTH / 4 + 10)
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

	coord.x = CENTER_MENU;
	coord.y = COLOR_TAB;
	put_str(vars, coord, TITLE_COLOR, "-- CHOSE COLOR --");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Terrain: press 1");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "White to red: press 2");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Blue to orange: press 3");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "White: press 4");

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
}

void	map_info_str(t_vars *vars)
{
	t_point coord;
	
	coord.x = CENTER_MENU;
	coord.y = MAP_INFO_TAB;
	put_str(vars, coord, TITLE_COLOR, "- MAP INFO -");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map width: ");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map length: ");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map max height: ");
	coord.y += LINE_BREAK;
	put_str(vars, coord, TEXT_COLOR, "Map height: ");

}

void	draw_menu(t_vars *vars)
{
	t_point coord;

	coord.x = CENTER_MENU + 10;
	coord.y = LINE_BREAK * 2;
	put_str(vars, coord, TITLE_COLOR, "     MENU   ");
	coord.y += 10;
	put_str(vars, coord, TITLE_COLOR, "_____________");
	map_info_str(vars);
	color_mode_str(vars);
	view_mode_str(vars);
}
