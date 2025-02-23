/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_in_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/02/12 16:45:31 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	map_data(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (vars->map.map[i] != NULL)
	{
		j = 0;
		while (vars->map.map[i][j] != '\0')
			j++;
		i++;
	}
	vars->map.width = j/2; //ATTENTION IL FAUDRAIT GERER LES ERREUR D'ESPACES, PEUT ETRE CREER UN TABLEAU DE INT
	vars->map.height = i/2;
}

int	check_length(int length, char *string)
{
	int	string_length;

	string_length = ft_strlen(string);
	if (length == -1)
		return (string_length);
	if (string_length != length)
		return (-1);
	return (string_length);
}

void	error_matrix(char *str1, char *str2, char *msg)
{
	if (str1 != NULL)
		free(str1);
	if (str2 != NULL)
		free(str2);
	exit_error(msg);
}

char	*get_full_line(int fd, int is_eof)
{
	char	*line;
	char	*buffer;
	int		length;

	length = -1;
	buffer = NULL;
	while (is_eof != 1)
	{
		line = get_next_line(fd, &is_eof);
		if (line == NULL && is_eof == -1)
			error_matrix(line, buffer, "Get_next_line error\n");
		if (line == NULL)
			break ;
		length = check_length(length, line);
		if (length == -1)
			error_matrix(line, buffer, "Wrong map configuration\n");
		if (buffer == NULL)
			buffer = line;
		else
			buffer = ft_strjoin(buffer, line);
		if (buffer == NULL)
			error_matrix(line, buffer, "Strjoin error\n");
	}
	free(line);
	return (buffer);
}

char	**put_in_matrix(char *argv[])
{
	int		fd;
	char	*full_line;
	char	**map;

	fd = open(argv[1], O_RDONLY);
	full_line = get_full_line(fd, 0);
	map = ft_split(full_line, '\n');
	if (map == NULL)
		error_matrix(NULL, full_line, "Split error\n");
	free(full_line);
	return (map);
}
