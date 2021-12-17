/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_world.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 17:02:02 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/30 19:16:16 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

void	texture_select(t_main *main)
{
	if (main->inf.side == 0 && main->inf.rayDirX > 0)
		main->inf.texNum = 1;
	else if (main->inf.side == 1 && main->inf.rayDirY < 0)
		main->inf.texNum = 2;
	else if (main->inf.side == 1 && main->inf.rayDirY > 0)
		main->inf.texNum = 3;
	else
		main->inf.texNum = 0;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	my_mlx_get_pixel(t_img *data, int x, int y)
{
	return (*(unsigned int *)(data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8))));
}
