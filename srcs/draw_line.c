/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 13:42:34 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	put_pixel(int x, int y, t_data_img *img, int color)
{
	char	*dst;

	if (x <= (WIN_WIDTH + MENU_WIDTH) && x >= MENU_WIDTH && \
			y <= WIN_HEIGHT && y >= 0)
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

// data[0] : direction
// data[1], data[2] : i, j
// data[3] : p, decision factor
// data[4] : color
void	verti_slope(t_point origin, t_point dest, t_vars *vars, t_point diff)
{
	int		dat[5];
	t_point	point;

	dat[0] = 1;
	dat[1] = 0;
	dat[2] = 0;
	if (origin.x > dest.x)
		dat[0] = -1;
	dat[3] = 2 * diff.x - diff.y;
	if (diff.y != 0)
	{
		while (origin.y + dat[1] != dest.y)
		{
			point.x = origin.x + dat[2];
			point.y = origin.y + dat[1];
			dat[4] = set_pix_color(dest, origin, point);
			put_pixel(origin.x + dat[2], origin.y + dat[1], &vars->img, dat[4]);
			dat[3] += 2 * diff.x - 2 * diff.y;
			if (dat[3] >= 0)
				dat[2] += dat[0];
			else
				dat[3] += 2 * diff.y;
			dat[1]++;
		}
	}
}

void	hori_slope(t_point origin, t_point dest, t_vars *vars, t_point diff)
{
	t_point	point;
	int		dat[5];

	dat[0] = 1;
	dat[1] = 0;
	dat[2] = 0;
	if (origin.y > dest.y)
		dat[0] = -1;
	dat[3] = 2 * diff.y - diff.x;
	if (diff.x != 0)
	{
		while (origin.x + dat[2] != dest.x)
		{
			point.x = origin.x + dat[2];
			point.y = origin.y + dat[1];
			dat[4] = set_pix_color(origin, dest, point);
			put_pixel(origin.x + dat[2], origin.y + dat[1], &vars->img, dat[4]);
			dat[3] += 2 * diff.y - 2 * diff.x;
			if (dat[3] >= 0)
				dat[1] += dat[0];
			else
				dat[3] += 2 * diff.x;
			dat[2]++;
		}
	}
}

void	draw_line(t_point origin, t_point dest, t_vars *vars)
{
	t_point	diff;

	diff.x = abs(dest.x - origin.x);
	diff.y = abs(dest.y - origin.y);
	if (diff.x < diff.y)
	{
		if (origin.y > dest.y)
			inverse_value(&origin, &dest);
		verti_slope(origin, dest, vars, diff);
	}
	else
	{
		if (origin.x > dest.x)
			inverse_value(&origin, &dest);
		hori_slope(origin, dest, vars, diff);
	}
}
