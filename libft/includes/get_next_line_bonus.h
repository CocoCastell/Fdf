/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 15:39:57 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <dlfcn.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list_gnl
{
	int					fd;
	char				*string;
	struct s_list_gnl	*next;
}		t_list_gnl;

t_list_gnl	*find_last_node(t_list_gnl *list, int fd, int flag, int node_nb);
int			make_list(t_list_gnl **list, int fd);
int			ft_strlen_gnl(const char *str);
int			add_node(t_list_gnl **list, char *str, int fd, int i);
bool		check_newline(t_list_gnl **list, int fd);
void		free_list(t_list_gnl **lst, int fd, int nd_nb, t_list_gnl *next_nd);
char		*extract_line(t_list_gnl *head, int fd, int i);
char		*get_next_line(int fd, int *error);

#endif
