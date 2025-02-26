/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 19:16:36 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(int x, int y, t_data_img *img, int color)
{
	char	*dst;

	if (x <= (WIN_WIDTH + MENU_WIDTH) && x >= MENU_WIDTH && y <= WIN_HEIGHT && y >= 0)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

void	inverse_value(t_point *a, t_point *b)
{
	int	tmp;

	tmp = a->x;
	a->x = b->x;
	b->x = tmp;
	tmp = a->y;
	a->y = b->y;
	b->y = tmp;
}

void    slope_bigger_than_one(t_point origin, t_point dest, t_vars *vars, t_point diff)
{
	int		p;
	int		direction;
	int		color;
	int		i = 0;
	int		j = 0;
	t_point	point;

	direction = 1;
	if (origin.y > dest.y)
		inverse_value(&origin, &dest);
	if (origin.x > dest.x)
		direction = -1;
	p = 2 * diff.x - diff.y;
    if (diff.y != 0)
	{
		while (origin.y + i != dest.y)
		{
			point.x = origin.x + j;
			point.y = origin.y + i;
			color = set_pix_color(dest, origin, point, vars);
			put_pixel(origin.x + j, origin.y + i, &vars->img, color);
			p += 2 * diff.x - 2 * diff.y;
			if (p >= 0)
				j += direction;
			else
				p += 2 * diff.y;
			i++;
		}
	}
}

void	slope_smaller_than_one(t_point origin, t_point dest, t_vars *vars, t_point diff)
{
	int		p;
	int		direction;
	t_point	point;
	int		j = 0;
	int		i = 0;
	int		color;

	direction = 1;
	if (origin.x > dest.x)
		inverse_value(&origin, &dest);
	if (origin.y > dest.y)
		direction = -1;
	p = 2 * diff.y - diff.x;
	if (diff.x != 0)
	{
		while (origin.x + j != dest.x)
		{
			point.x = origin.x + j;
			point.y = origin.y + i;
			color = set_pix_color(origin, dest, point, vars);
			put_pixel(origin.x + j, origin.y + i, &vars->img, color);
			p += 2 * diff.y - 2 * diff.x;
			if (p >= 0)
				i += direction;
			else
				p += 2 * diff.x;
			j++;
		}
	}
}

void	draw_line(t_point origin, t_point dest, t_vars *vars)
{
	t_point	diff;

	diff.x = abs(dest.x - origin.x);
	diff.y = abs(dest.y - origin.y);
	if (diff.x < diff.y)
		slope_bigger_than_one(origin, dest, vars, diff);
	else
		slope_smaller_than_one(origin, dest, vars, diff);
}
