/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/01/20 19:25:02 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line_bonus.h"
//Allibera els nodes amb el fd correcte i reconnecta els altres en aquest cas

void	free_list(t_list_gnl **lst, int fd, int nd_nb, t_list_gnl *next_nd)
{
	t_list_gnl	*current;
	t_list_gnl	*temp;

	current = *lst;
	while (current)
	{
		if (current->fd == fd)
		{
			if (next_nd == NULL)
				*lst = current->next;
			else
				next_nd->next = current->next;
			temp = current;
			current = current->next;
			free(temp->string);
			free(temp);
			nd_nb++;
			continue ;
		}
		next_nd = current;
		current = current->next;
	}
	if (nd_nb == 0)
		*lst = NULL;
}

void	add_node(t_list_gnl **list, char *str, int fd, int i)
{
	t_list_gnl	*new_node;
	t_list_gnl	*last_node;

	if (str == NULL)
		return ;
	new_node = malloc(sizeof(t_list_gnl));
	if (new_node == NULL)
		return ;
	new_node->string = malloc(ft_strlen_gnl(str) + 1);
	if (new_node->string == NULL)
	{
		free(new_node);
		return ;
	}
	new_node->fd = fd;
	new_node->next = NULL;
	while (str[++i] != '\0')
		new_node->string[i] = str[i];
	new_node->string[i] = '\0';
	last_node = find_last_node(*list, fd, 0, 0);
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
}

int	make_list(t_list_gnl **list, int fd)
{
	ssize_t	bytes_read;
	char	*buffer;

	while (check_newline(list, fd) == false)
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (-1);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(buffer);
			if (bytes_read == 0)
				return (0);
			else
				return (-1);
		}
		buffer[bytes_read] = '\0';
		add_node(list, buffer, fd, -1);
		free(buffer);
	}
	return (0);
}

void	end_node(t_list_gnl **list, t_list_gnl *last_node, int fd)
{
	int			j;
	int			i;
	char		*str;

	j = 0;
	i = 0;
	while (last_node->string[i] != '\n' && last_node->string[i] != '\0')
		i++;
	if (last_node->string[i] == '\n' && last_node->string[++i] != '\0')
	{
		str = malloc(ft_strlen_gnl(last_node->string) - i + 1);
		if (str == NULL)
			return ;
		while (last_node->string[i] != '\0')
			str[j++] = last_node->string[i++];
		str[j] = '\0';
		free_list(list, fd, 0, NULL);
		last_node = find_last_node(*list, fd, 0, 0);
		add_node(list, str, fd, -1);
		free(str);
		return ;
	}
	free_list(list, fd, 0, NULL);
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*list;
	t_list_gnl			*last_node;
	char				*next_line;
	int					check;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	check = make_list(&list, fd);
	if (check == -1 || list == NULL)
		return (NULL);
	last_node = find_last_node(list, fd, 1, 0);
	if (last_node == NULL || last_node->fd != fd)
		return (NULL);
	next_line = extract_line(list, fd, 0);
	end_node(&list, last_node, fd);
	return (next_line);
}
