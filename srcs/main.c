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

void	print_map(char **map)
{
	int	i = 0;

	while (map[i] != NULL)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	char	**map;

	if (argc != 2)
		return (ft_printf("Wrong number of arguments\n"), 1);
	map = put_in_matrix(argv);
	print_map(map);
	return (0);
}
