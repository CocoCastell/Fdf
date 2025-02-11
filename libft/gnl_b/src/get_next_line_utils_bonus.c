/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/01/20 19:20:25 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"

//Si flag=1 -> Retorna l'ultim node amb el fd corresponent
//Si flag=0 -> Retorna l'ultim node de la llista
t_list_gnl	*find_last_node(t_list_gnl *list, int fd, int flag, int node_nb)
{
	t_list_gnl	*temp;

	temp = list;
	if (temp == NULL)
		return (NULL);
	while (flag == 1 && temp->next != NULL)
	{
		if (temp->fd == fd)
			node_nb++;
		temp = temp->next;
	}
	if (flag == 1 && temp != NULL && temp->fd == fd)
		node_nb++;
	while (node_nb == 0 && temp->next != NULL)
		temp = temp->next;
	if (node_nb > 0)
		temp = list;
	while (node_nb > 0)
	{
		if (temp->fd == fd)
			node_nb--;
		if (temp->next != NULL && node_nb > 0)
			temp = temp->next;
	}
	return (temp);
}

bool	check_newline(t_list_gnl **list, int fd)
{
	int			i;
	t_list_gnl	*last_node;

	i = 0;
	if (*list == NULL)
		return (false);
	last_node = find_last_node(*list, fd, 1, 0);
	if (last_node == NULL || last_node->string == NULL)
		return (false);
	while (last_node->string[i] != '\0')
	{
		if (last_node->string[i] == '\n' && last_node->fd == fd)
			return (true);
		i++;
	}
	return (false);
}

int	ft_strlen_gnl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static char	*make_line(t_list_gnl *temp, int length, int fd, int i)
{
	char	*str;
	int		j;

	str = malloc(length + 1);
	if (str == NULL)
		return (NULL);
	while (temp != NULL)
	{
		if (fd == temp->fd)
		{
			j = 0;
			while (temp->string[j] != '\0' && temp->string[j] != '\n')
				str[i++] = temp->string[j++];
			if (temp->string[j] == '\n')
			{
				str[i++] = '\n';
				break ;
			}
		}
		temp = temp->next;
	}
	str[i] = '\0';
	return (str);
}

//Calcula la llagarda de la linea i crea amb la funcio make_line
char	*extract_line(t_list_gnl *head, int fd, int i)
{
	t_list_gnl	*temp;
	char		*str;
	int			length;

	temp = head;
	length = 0;
	while (temp != NULL)
	{
		if (fd == temp->fd)
		{
			i = 0;
			while (temp->string[i] != '\0' && temp->string[i++] != '\n')
				length++;
			if (temp->string[i - 1] == '\n')
			{
				length++;
				break ;
			}
		}
		temp = temp->next;
	}
	temp = head;
	str = make_line(temp, length, fd, 0);
	return (str);
}
