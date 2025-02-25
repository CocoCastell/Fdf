/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 17:46:21 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/05 17:27:05 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_free_matrix(int **matrix, int rows)
{
	int	i;
	
	i = 0;
	if (matrix != NULL)
		return ;
	while (i < rows)
	{
		if (matrix[i] != NULL)
			free(matrix[i++]);
	}
	free(matrix);
}
