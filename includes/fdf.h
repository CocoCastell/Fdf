/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 17:50:21 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx_linux/mlx.h"
# include "../mlx_linux/mlx_int.h"
# include "../libft/includes/libft.h"
# include "../libft/includes/get_next_line_bonus.h"
# include "../libft/includes/ft_printf_bonus.h"
# include <math.h>
# include <stdlib.h>

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define LINE 20
# define ESC 65307
# define RIGHT_CLIC 3
# define LEFT_CLIC 1
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5

///////////////////////////
//|	Structures	|//
///////////////////////////

typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_length;
	int	endian;
	int	frame_count;	
}		t_data_img;

typedef struct s_map
{
	int	width;
	int	height;
	char	**map;
}		t_map;

typedef struct s_camera
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int	zoom;
}		t_camera;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_camera	*camera;
	t_map		map;
	t_data_img	img;
}		t_vars;

typedef struct s_point
{
        int     x;
        int     y;
	int	z;
}               t_point;

///////////////////////////
//|	Functions	|//
///////////////////////////

// Error

void	exit_error(char *msg, int error);
void	free_error(t_vars *vars, char *msg, int error);

// Algo

void	map_data(t_vars *vars);
void	draw_line(t_point origin, t_point dest, t_vars *vars);
char	**put_in_matrix(char *argv[]);
void	window_manager(t_vars *vars);
void	rendering_map(t_vars *vars);

#endif
