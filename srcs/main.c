/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/26 18:34:52 by cochatel         ###   ########.fr       */
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
		apply_changes_and_draw(origin, dest, vars);
	}
	if (i < vars->map.y_axis)
	{
		dest.y = i + 1;
		dest.x = j;
		dest.z = vars->map.map[i][j - 1];
		apply_changes_and_draw(origin, dest, vars);
	}
}

void	render_window(t_vars *vars)
{
	int	i;
	int	j;

	i = -1;
	ft_bzero(vars->img.addr, WIN_HEIGHT * (WIN_WIDTH + MENU_WIDTH) * (vars->img.bpp / 8));
	draw_background(vars);
	while (++i < vars->map.y_axis)
	{
		j = -1;
		while (++j < vars->map.x_axis)
			render_map(i + 1, j + 1, vars);
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img.img, 0, 0);
	draw_menu(vars);
}

void    event_manager(t_vars *vars)
{
	mlx_hook(vars->win, ClientMessage, StructureNotifyMask, my_close, vars);
	mlx_hook(vars->win, KeyPress, KeyPressMask, key_pressed, vars);
	//mlx_hook(vars->win, KeyRelease, KeyReleaseMask, key_released, vars);
	mlx_hook(vars->win, ButtonPress, ButtonPressMask, mouse_pressed, vars);
	mlx_hook(vars->win, ButtonRelease, ButtonReleaseMask, mouse_released, vars);
	mlx_hook(vars->win, MotionNotify, PointerMotionMask, mouse_move, vars);
	(void)vars;
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc == 2)
	{
		ft_mlx_init(&vars);
		get_map(argv, &vars);
		event_manager(&vars);
		render_window(&vars);
		mlx_loop(vars.mlx);
	}
	else
		return (ft_printf("Wrong number of arguments\n"), 1);
	return (0);
}
