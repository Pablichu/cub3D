/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_aux.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:52:15 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 15:08:37 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	speed_mark(t_main *main)
{
	if (main->ply.speed > 0.1)
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->txt[12].img, 100, 805);
	if (main->ply.speed > 0.25)
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->txt[12].img, 170, 805);
	if (main->ply.speed > 0.4)
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->txt[12].img, 240, 805);
	if (main->ply.speed > 0.55)
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->txt[13].img, 310, 805);
}

void	hud(t_main *main)
{
	if (main->ply.ship)
	{
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->txt[11].img, 50, 750);
		if (main->ply.lives)
		{
			mlx_string_put(main->mlx.mlx, main->mlx.win, 75, 950,
				0X00FF5248, "- Hit detected");
			mlx_string_put(main->mlx.mlx, main->mlx.win, 79, 960,
				0X00FF5248, "Cannot control speed");
		}
		if (main->ply.lives == 2)
		{
			mlx_string_put(main->mlx.mlx, main->mlx.win, 75, 975,
				0X00FF5248, "- Hit detected");
			mlx_string_put(main->mlx.mlx, main->mlx.win, 79, 985,
				0X00FF2020, "!!CRITICAL DAMAGE!!");
			mlx_string_put(main->mlx.mlx, main->mlx.win, 79, 995,
				0X00FF5248, "Stabilizators compromised");
		}
		speed_mark(main);
	}
}

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
