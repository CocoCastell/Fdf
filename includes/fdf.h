/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/25 17:44:26 by cochatel         ###   ########.fr       */
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
# include <limits.h>

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

enum e_mode
{
	TERRAIN,
	BLUE_TO_RED,
	BLACK_AND_WHITE
};

typedef struct s_color
{
	int	t;
	int	r;
	int	g;
	int	b;
}				t_color;

typedef struct s_data_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
	int		frame_count;	
}		t_data_img;

typedef struct s_map
{
	int				**map;
	int				x_axis;
	int				y_axis;
	int				z_max;
	int				z_min;
	t_color			max_color;
	t_color			min_color;
	enum e_mode	color_mode;
}		t_map;

typedef struct s_camera
{
	double	x_angle;
	double	y_angle;
	double	z_angle;
	int		zoom;
}		t_camera;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_camera	camera;
	t_map		map;
	t_data_img	img;
}		t_vars;

typedef struct s_point
{
        int     x;
        int     y;
		int		z;
		t_color	color;
}               t_point;

///////////////////////////
//|	Functions	|//
///////////////////////////

// Error

void	exit_error(char *msg, int error);
void	free_error(t_vars *vars, char *msg, int error);
void	error_map(char *str1, char *str2, t_vars *vars, char *msg);

// Utils

int	find_offset(t_map map, t_camera camera);
t_point	new_map_center(t_vars *vars);

// Map

char	*get_full_line(int fd, int is_eof, t_vars *vars);
void	map_init(char *argv[], t_vars *vars);

// Geometry

void	center(t_point *point, t_point map_center);
void	scale(t_point *point, t_camera camera);
void	isometric_projection(t_point *point, t_camera camera);
void	isometric_view(t_point origin, t_point dest, t_vars *vars);

// Algo

void	draw_line(t_point origin, t_point dest, t_vars *vars);
void	event_manager(t_vars *vars);
void	render_map(t_vars *vars);

// Color

int		create_color(int t, int r, int g, int b);
void	set_point_color(t_point *point, t_vars *vars);
int		find_color(int max_color, int min_color, t_vars *vars, int height_point);
int		set_pixel_color(t_point origin, t_point dest, t_point pixel, t_vars *vars);

// Mode

void	blue_to_orange(t_vars *vars);

#endif
