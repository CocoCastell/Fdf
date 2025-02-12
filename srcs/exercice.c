/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/11 15:13:34 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		frame_count;
}				t_data;

typedef struct s_circle
{
	int	y;
	int	x;
	int	radius;
	int	color;
}			t_circle;

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_vars
{
	void    *mlx;
	void    *win;
	t_data  img;
	t_circle circle;
}       t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int colors)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8 ));
	*(unsigned int *)dst = colors;
}

int	add_shade(int color, double distance)
{
	int	t, r, g, b;
	
	t = color >> 24 & 0xFF;
	r = color >> 16 & 0xFF;
	g = color >> 8 & 0xFF;
	b = color & 0xFF;

	t = t - (t * distance);
	r = r - (r * distance);
	g = g - (g * distance);
	r = r - (r * distance);

	return (t << 24 | r << 16 | g << 8 | b);
}

int	create_color(int t, int r, int g, int b)
{
	return (t << 24 | r << 16| g << 8 | b);
}

void	delete_circle(t_vars *vars, int x0, int y0, int radius)
{
	int	x, y;

	for (y = -radius; y < radius; y++)
	{
		for (x = -radius; x < radius; x++)
		{
			if ((x * x + y *y) <= radius * radius && ((x + x0) < 700 && (x + x0) > 0) && ((y + y0) < 600 && (y + y0 > 0)))
				my_mlx_pixel_put(&vars->img, x + x0, y + y0, 0x00ff0000);
		}
	}
}

void	draw_circle(t_vars *vars, int x0, int y0, int radius, int color)
{
	int x, y;

	for (y = -radius; y < radius; y++)
	{
		for (x = -radius; x < radius; x++)
		{
			if ((x * x + y *y) <= radius * radius && ((x + x0) < 700 && (x + x0) > 0) && ((y + y0) < 600 &&     (y + y0 > 0)))
				my_mlx_pixel_put(&vars->img, x + x0, y + y0, color);
		}
	}
}

int	play(int keycode, t_vars *vars)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	if (keycode == LEFT)
	{
		delete_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius);
		vars->circle.color = create_color(0, 0, 250, 0);
		vars->circle.x -=  10;
		vars->circle.radius = 50;
		draw_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius, vars->circle.color);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (keycode == RIGHT)
	{
		delete_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius);
		vars->circle.color = create_color(0, 0, 250, 0);
		vars->circle.x += 10;
		vars->circle.radius = 50;
		draw_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius, vars->circle.color);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (keycode == UP)
	{
		delete_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius);
		vars->circle.color = create_color(0, 0, 250, 0);
		vars->circle.y -= 10;
		vars->circle.radius = 50;
		draw_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius, vars->circle.color);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (keycode == DOWN)
	{
		delete_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius);
		vars->circle.color = create_color(0, 0, 250, 0);
		vars->circle.y += 10;
		vars->circle.radius = 50;
		draw_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius, vars->circle.color);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

int	put_circle(int keycode, int x, int y, t_vars *vars)
{
	if (keycode == LEFT_CLIC)
	{
		vars->circle.color = create_color(0, 0, 250, 0);
		vars->circle.x = x;
		vars->circle.y = y;
		vars->circle.radius = 50;
		draw_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius, vars->circle.color);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	if (keycode == RIGHT_CLIC)
	{
		vars->circle.x = x;
		vars->circle.y = y;
		vars->circle.radius = 50;
		delete_circle(vars, vars->circle.x, vars->circle.y, vars->circle.radius);
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

int	bye(t_vars *vars)
{
	(void)vars;
	printf("bye\n");
	return (0);
}

int	hello(t_vars *vars)
{
	(void)vars;
	printf("hello\n");
	return (0);
}

int	my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	rainbow(t_vars *vars)
{
	int color;

	vars->img.frame_count += 1;
	if (vars->img.frame_count > 200)
	{
		color = create_color(250, 0, 0, 250);
		for (int	i = 50; i < 500; i++)
		{
			for (int j = 50; j < 500; j++)
				my_mlx_pixel_put(&vars->img, i, j, color);
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
		if (vars->img.frame_count == 400)
			vars->img.frame_count = 0;
	}
	else
	{
		color = create_color(250, 250, 0, 0);
		for (int	i = 50; i < 500; i++)
		{
			for (int j = 50; j < 500; j++)
				my_mlx_pixel_put(&vars->img, i, j, color);
		}
		mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	}
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 920, 800, "Marina la guapa");
	vars.img.img = mlx_new_image(vars.mlx, 700, 600);
	vars.img.addr = mlx_get_data_addr(vars.img.img, &vars.img.bits_per_pixel, &vars.img.line_length, &vars.img.endian);
	int color = create_color(0, 250, 0, 0);
	vars.img.frame_count = 0;
	for (int i = 50; i < 500; i++)
	{
		for (int j = 50; j < 500; j++)
			my_mlx_pixel_put(&vars.img, i, j, color);
	}
	mlx_hook(vars.win, 4, 1L<<2, put_circle, &vars);
	mlx_hook(vars.win, ClientMessage, StructureNotifyMask, my_close, &vars);
	mlx_hook(vars.win, 2, 1L<<0, play, &vars);
	mlx_hook(vars.win, EnterNotify, EnterWindowMask, hello, &vars);
	mlx_hook(vars.win, LeaveNotify, LeaveWindowMask, bye, &vars);
	mlx_loop_hook(vars.mlx, rainbow, &vars);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0, 0);
	mlx_loop(vars.mlx);
}
