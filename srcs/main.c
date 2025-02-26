/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 16:49:42 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    render_map(int i, int j, t_vars *vars)
{
        t_point dest;
	t_point origin;

	origin.x = j;
	origin.y = i;
	origin.z = vars->map.map[i - 1][j - 1];
	if (j < vars->map.x_axis)
	{
		dest.y = i;
		dest.x = j + 1;
		dest.z = vars->map.map[i - 1][j];
		isometric_view(origin, dest, vars);
	}
	if (i < vars->map.y_axis)
	{
		dest.y = i + 1;
		dest.x = j;
		dest.z = vars->map.map[i][j - 1];
		isometric_view(origin, dest, vars);
	}
}

void	render_window(t_vars *vars)
{
	int	i;
	int	j;
	
	i = -1;
	ft_bzero(vars->img.addr, WIN_HEIGHT * WIN_WIDTH * (vars->img.bpp / 8));
	draw_menu(vars);
	/*t_point a;
	t_point b;

	a.x = WIN_WIDTH / 2 - 20;
	a.y = WIN_HEIGHT / 2;
	b.x = WIN_WIDTH / 2 + 20;
	b.y = WIN_HEIGHT / 2;
	draw_line(a, b, vars);
	a.x = WIN_WIDTH / 2;
	a.y = WIN_HEIGHT / 2 - 20;
	b.x = WIN_WIDTH / 2;
	b.y = WIN_HEIGHT / 2 + 20;
	draw_line(a, b, vars);
	*/
	while (++i < vars->map.y_axis)
	{
		j = -1;
		while (++j < vars->map.x_axis)
			render_map(i + 1, j + 1, vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	put_menu_strings(vars);
}

void	ft_mlx_init(t_vars *vars)
{
	vars->mlx = mlx_init();
	if (vars->mlx == NULL)
		exit_error("Mlx init error\n", 1);
	vars->win = mlx_new_window(vars->mlx, WIN_WIDTH + MENU_WIDTH, WIN_HEIGHT, "Rendering");
	if (vars->win == NULL)
		free_error(vars, "Win init error\n", 1);
	vars->img.img = mlx_new_image(vars->mlx, WIN_WIDTH + MENU_WIDTH, WIN_HEIGHT);
	if (vars->img.img == NULL)
		free_error(vars, "Img init error\n", 1);
	vars->img.addr = mlx_get_data_addr(vars->img.img, &vars->img.bpp, &vars->img.line_length, &vars->img.endian);
	if (vars->img.addr == NULL)
		free_error(vars, "Img addr init error\n", 1);
	vars->map.map = NULL;
	vars->map.x_axis = 0;
	vars->map.y_axis = 0;
	vars->map.z_max = 0;
	vars->map.z_min = 0;
}

void	init_camera(t_camera *camera)
{
	camera->zoom = 25;
	camera->x_angle = 0.5236;
}


int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		ft_mlx_init(&vars);
		map_init(argv, &vars);
		init_camera(&vars.camera);
		event_manager(&vars);
		render_window(&vars);
		mlx_loop(vars.mlx);
	}
	else
		return (ft_printf("Wrong number of arguments\n"), 1);
	return (0);
}
