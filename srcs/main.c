/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:47:58 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	apply_zoom_and_center(t_point *point, t_vars *vars)
{
	point->x *= vars->camera.zoom; 
	point->y *= vars->camera.zoom; 
	point->z *= vars->camera.zoom; 
	point->x += (vars->map.width / 2) * vars->camera.zoom;
	point->y += (vars->map.height / 2) * vars->camera.zoom;
}

void	isometric_projection(t_point *point, t_vars *vars)
{
	int	tmp;
	tmp = point->x;
	point->x = (point->x - point->y) * cos(vars->camera.x_angle); 
	point->y = (tmp + point->y) * sin(vars->camera.x_angle) - point->z;
}

void	isometric_view(t_point origin, t_point dest, t_vars *vars)
{
	apply_zoom_and_center(&origin, vars);
	apply_zoom_and_center(&dest, vars);
	isometric_projection(&origin, vars);
	isometric_projection(&dest, vars);
	draw_line(origin, dest, vars);
}

void    send_to_draw(int i, int j, t_vars *vars, char **line[2])
{
        t_point dest;
	t_point origin;

	origin.x = j;
	origin.y = i;
	origin.z = atoi(line[0][j - 1]);
	ft_printf("RENDER: %d\n", vars->camera.zoom);
	if (line[0][j] != NULL)
	{
		dest.y = i;
		dest.x = j + 1;
		dest.z = atoi(line[0][j]);		
		isometric_view(origin, dest, vars);
	}
	if (line[1] != NULL)
	{
		dest.y = i + 1;
		dest.x = j;
		dest.z = atoi(line[1][j - 1]);
		isometric_view(origin, dest, vars);
	}
}

void	rendering_map(t_vars *vars)
{
	char	**line[2];
	int	i;
	int	j;
	
	i = -1;
	while (vars->map.map[++i] != NULL)
	{
		j = -1;
		line[0] = ft_split(vars->map.map[i], ' ');
		line[1] = ft_split(vars->map.map[i + 1], ' ');
		while (++j <= vars->map.width)
			send_to_draw(i + 1, j + 1, vars, line);
		free(line[0]);
		free(line[1]);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
}

void	ft_mlx_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit_error("Mlx init error\n", 1);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH, WIN_HEIGHT, "Rendering");
	if (vars->win == NULL)
		free_error(vars, "Win init error\n", 1);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (vars->img.img == NULL)
		free_error(vars, "Img init error\n", 1);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		free_error(vars, "Img addr init error\n", 1);
	vars->camera = NULL;
	vars->map.map = NULL;
	vars->map.width = 0;
	vars->map.height = 0;
}

void	mlx_manager(t_vars *vars)
{
	ft_init_mlx(vars);
	window_manager(vars);
	rendering_map(vars);
	mlx_clear_window(vars->mlx, vars->win);            
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH, WIN_HEIGHT);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bits_per_pixel, &vars->img.line_length, &vars->img.endian);
	rendering_map(vars);
	mlx_loop(vars->mlx);
}

void	init_camera(t_camera *camera)
{
	camera->zoom = 20;
	camera->x_angle = 0.5236;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		ft_mlx_init(&vars);
		vars.map.map = put_in_matrix(argv);
		init_camera(&vars.camera);
		event_manager(&vars);
		mlx_rendering(&vars);
		mlx_loop(vars->mlx);
	}
	else
		return (ft_printf("Wrong number of arguments\n"), 1);
	return (0);
}
