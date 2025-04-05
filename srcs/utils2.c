/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2025/03/08 12:33:14 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	select_gradient_mode(int keycode, t_event *event)
{
	if (keycode == T)
		event->is_terrain = true;
	if (keycode == C)
		event->is_terrain = false;
}

void	select_view_mode(t_camera *camera)
{
	if (camera->view_mode == 0)
		camera->view_mode = 1;
	else
		camera->view_mode = 0;
}
