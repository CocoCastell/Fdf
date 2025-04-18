/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 16:32:01 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//to center the map in the window
void	find_min_max_z(t_map *map)
{
	int	i;
	int	j;
	int	max;
	int	min;

	i = 0;
	max = INT_MIN;
	min = INT_MAX;
	while (i < map->y_axis)
	{
		j = 0;
		while (j < map->x_axis)
		{
			if (map->map[i][j] > max)
				max = map->map[i][j];
			if (map->map[i][j] < min)
				min = map->map[i][j];
			j++;
		}
		i++;
	}
	map->z_max = max;
	map->z_min = min;
}

int	get_matrix(t_vars *vars, int ***new_map, char **map)
{
	int		i;
	int		j;
	char	**line;

	*new_map = malloc(sizeof(int *) * vars->map.y_axis);
	if (*new_map == NULL)
		return (1);
	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		line = ft_split(map[i], ' ');
		if (line == NULL)
			return (ft_free_matrix(*new_map, i), 1);
		(*new_map)[i] = malloc(sizeof(int *) * vars->map.x_axis);
		if ((*new_map)[i] == NULL)
			return (ft_free_string_array(line), ft_free_matrix(*new_map, i), 1);
		while (line[++j] != NULL)
			(*new_map)[i][j] = ft_atoi(line[j]);
		if (j > vars->map.x_axis)
			return (ft_free_matrix(*new_map, i), 2);
		ft_free_string_array(line);
	}
	vars->map.map = *new_map;
	return (0);
}

int	map_lengths(char **map, int *rows, int *cols)
{
	char	**line;
	int		cmp;

	cmp = 0;
	while (map[*rows] != NULL)
	{
		*cols = 0;
		line = ft_split(map[*rows], ' ');
		if (line == NULL)
			return (-1);
		while (line[*cols] != NULL)
			(*cols)++;
		ft_free_string_array(line);
		(*rows)++;
		if (cmp == 0)
			cmp = *cols;
		if (cmp != *cols && cmp != 0)
			return (-1);
	}
	*cols = cmp;
	return (0);
}

char	*get_full_line(int fd, int is_eof, t_vars *vars)
{
	char	*line;
	char	*buffer;
	char	*temp;

	buffer = NULL;
	while (is_eof != 1)
	{
		line = get_next_line(fd, &is_eof);
		if (line == NULL && is_eof == -1)
			error_map(line, buffer, vars, "Get_next_line error\n");
		if (line == NULL)
			break ;
		temp = ft_strjoin(buffer, line);
		if (temp == NULL)
			error_map(line, buffer, vars, "Strjoin error\n");
		free(line);
		if (buffer != NULL)
			free(buffer);
		buffer = temp;
	}
	return (buffer);
}

void	get_map(char *argv[], t_vars *vars)
{
	int		fd;
	char	*full_line;
	char	**map;
	int		**new_map;

	fd = open(argv[1], O_RDONLY);
	full_line = get_full_line(fd, 0, vars);
	close(fd);
	map = ft_split(full_line, '\n');
	free(full_line);
	if (map == NULL)
		free_error(vars, "Split error\n", 1);
	new_map = NULL;
	if (map_lengths(map, &vars->map.y_axis, &vars->map.x_axis) == -1)
		free_error(vars, "Map error\n", 1);
	if (get_matrix(vars, &new_map, map) > 0)
		error_map(NULL, NULL, vars, "Map error\n");
	find_min_max_z(&vars->map);
	ft_free_string_array(map);
}
