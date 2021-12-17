/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:52:15 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/26 19:57:53 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

int	calculating_stepX(t_main *main)
{
	if (main->inf.rayDirX < 0)
	{
		main->inf.sideDistX = (main->ray.posX - main->inf.mapX)
			* main->ray.deltaDistX;
		return (-1);
	}
	else
	{
		main->inf.sideDistX = (main->inf.mapX + 1.0 - main->ray.posX)
			* main->ray.deltaDistX;
		return (1);
	}
}

int	calculating_stepY(t_main *main)
{
	if (main->inf.rayDirY < 0)
	{
		main->inf.sideDistY = (main->ray.posY - main->inf.mapY)
			* main->ray.deltaDistY;
		return (-1);
	}
	else
	{
		main->inf.sideDistY = (main->inf.mapY + 1.0 - main->ray.posY)
			* main->ray.deltaDistY;
		return (1);
	}
}
