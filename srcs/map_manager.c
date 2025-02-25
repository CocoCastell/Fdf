/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:45:31 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//to center the map in the window
int	find_max_z(t_map map)
{
	int	i;
	int	j;
	int	z;
	
	i = 0;
	z = 0;
	while (i < map.y_axis)
	{
		j = 0;
		while (j < map.x_axis)
		{
			if (map.map[i][j] > z)
				z = map.map[i][j];
			j++;
		}
		i++;
	}
	return (z);
}

int	get_matrix(t_vars *vars, int **new_map, char **map)
{
	int	i;
	int	j;
	char	**line;

	new_map = malloc(sizeof(int *) * vars->map.y_axis);
	if (new_map == NULL)
		return (1);
	i = -1;
	while (map[++i] != NULL)
	{
		j = -1;
		line = ft_split(map[i], ' ');
		if (line == NULL)
			return (ft_free_matrix(new_map, i), 1);
		new_map[i] = malloc(sizeof(int *) * vars->map.x_axis);
		if (new_map[i] == NULL)
			return (free(line), ft_free_matrix(new_map, i), 1);
		while (line[++j] != NULL)
			new_map[i][j] = ft_atoi(line[j]);
		if (j > vars->map.x_axis)
			return (ft_free_matrix(new_map, i), 2);
		free(line);
	}
	vars->map.map = new_map;
	return (0);
}

void	init_map(char **map, t_vars *vars)
{
	int	i;
	int	j;
	int	m;
	int	**new_map;

	i = -1;
	m = 0;
	new_map = NULL;
	while (map[++i] != NULL)
	{
		j = -1;
		while (map[i][++j] != '\0')
		{
			if (map[i][j] >= '0' && map[i][j] <= '9')
				m++;
		}
	}
	vars->map.y_axis = i;
	vars->map.x_axis = m / i; //ATTENTION IL FAUDRAIT GERER LES ERREUR D'ESPACES, PEUT ETRE CREER UN TABLEAU DE INT
	if (get_matrix(vars, new_map, map) == 1)
		error_map(NULL, NULL, vars, "Map error\n");
	if (get_matrix(vars, new_map, map) == 2)
		error_map(NULL, NULL, vars, "Wrong map configuration\n");
	vars->map.z_axis = find_max_z(vars->map);
}

char	*get_full_line(int fd, int is_eof, t_vars *vars)
{
	char	*line;
	char	*buffer;

	buffer = NULL;
	while (is_eof != 1)
	{
		line = get_next_line(fd, &is_eof);
		if (line == NULL && is_eof == -1)
			error_map(line, buffer, vars, "Get_next_line error\n");
		if (line == NULL)
			break ;
		if (buffer == NULL)
			buffer = line;
		else
			buffer = ft_strjoin(buffer, line);
		if (buffer == NULL)
			error_map(line, buffer, vars, "Strjoin error\n");
	}
	free(line);
	return (buffer);
}

void	map_manager(char *argv[], t_vars *vars)
{
	int		fd;
	char	*full_line;
	char	**map;
	
	fd = open(argv[1], O_RDONLY);
	full_line = get_full_line(fd, 0, vars);
	close(fd);
	map = ft_split(full_line, '\n');
	if (map == NULL)
		error_map(NULL, full_line, vars, "Split error\n");
	free(full_line);
	init_map(map, vars);
	ft_free_string_array(map);
}
