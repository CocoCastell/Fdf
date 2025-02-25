/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 17:45:20 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    put_pixel(t_point point, t_data_img *img, int color)
{
	char	*dst;

	if (point.x <= WIN_WIDTH && point.x >= 0 && point.y <= WIN_HEIGHT && point.y >= 0)
	{
		dst = img->addr + (point.y * img->line_length + point.x * (img->bpp / 8 ));
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
	int	p;
	int	direction;
	int	color;
	t_point	f_pixel;
	t_point	l_pixel;
	
	f_pixel.color.r = origin.color.r;
	f_pixel.color.g = origin.color.g;
	f_pixel.color.b = origin.color.b;
	l_pixel.color.r = origin.color.r;
	l_pixel.color.g = origin.color.g;
	l_pixel.color.b = origin.color.b;
	direction = 1;
	if (origin.y > dest.y)
		inverse_value(&origin, &dest);
	if (origin.x > dest.x)
		direction = -1;
	p = 2 * diff.x - diff.y;
    if (diff.y != 0)
	{
		while (origin.y != dest.y)
		{
			color = set_pixel_color(f_pixel, l_pixel, origin, vars);
			put_pixel(origin, &vars->img, color);
			p += 2 * diff.x - 2 * diff.y;
			if (p >= 0)
				origin.x += direction;
			else
				p += 2 * diff.y;
			origin.y++;
		}
    }
}

void    slope_smaller_than_one(t_point origin, t_point dest, t_vars *vars, t_point diff)
{
        int     p;
	int	direction;
	
	direction = 1;
	if (origin.x > dest.x)
        	inverse_value(&origin, &dest);
	if (origin.y > dest.y)
        	direction = -1;
	p = 2 * diff.y - diff.x;
        if (diff.x != 0)
	{
		while (origin.x != dest.x)
		{
			put_pixel(origin, &vars->img, 0x0000FF00);
			p += 2 * diff.y - 2 * diff.x;
			if (p >= 0)
				origin.y += direction;
			else
				p += 2 * diff.x;
			origin.x++;
		}
        }
}

void    draw_line(t_point origin, t_point dest, t_vars *vars)
{
	t_point	diff;
	
	diff.x = abs(dest.x - origin.x);
        diff.y = abs(dest.y - origin.y);
	if (diff.x < diff.y)
		slope_bigger_than_one(origin, dest, vars, diff);
	else	
		slope_smaller_than_one(origin, dest, vars, diff);
}
