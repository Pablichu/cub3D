/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_steve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:33:54 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/07 21:35:17 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	moving_forwback(t_main *main, int gear)
{
	if (!ft_strchr("12", main->flnf.map[(int)(main->ray.posX + (main->ray.dirX
					* MVSPEED * gear))][(int)main->ray.posY]))
		main->ray.posX += (main->ray.dirX * MVSPEED * gear);
	if (!ft_strchr("12", main->flnf.map[(int)main->ray.posX][
			(int)(main->ray.posY + (main->ray.dirY * MVSPEED * gear))]))
		main->ray.posY += (main->ray.dirY * MVSPEED * gear);
}

static void	moving_lerigt(t_main *main, int gear)
{
	if (!ft_strchr("12", main->flnf.map[(int)(main->ray.posX + (main->ray.planeX
					* MVSPEED * gear))][(int)main->ray.posY]))
		main->ray.posX += (main->ray.planeX * MVSPEED * gear);
	if (!ft_strchr("12", main->flnf.map[(int)main->ray.posX][
			(int)(main->ray.posY + (main->ray.planeY * MVSPEED * gear))]))
		main->ray.posY += (main->ray.planeY * MVSPEED * gear);
}

static void	looking_for_love(t_main *main, int gear)
{
	double	oldDirX;
	double	oldPlaneX;

	oldDirX = main->ray.dirX;
	main->ray.dirX = main->ray.dirX * cos(ROTSPEED * gear) - main->ray.dirY
		* sin(ROTSPEED * gear);
	main->ray.dirY = oldDirX * sin(ROTSPEED * gear) + main->ray.dirY
		* cos(ROTSPEED * gear);
	oldPlaneX = main->ray.planeX;
	main->ray.planeX = main->ray.planeX * cos(ROTSPEED * gear)
		- main->ray.planeY * sin(ROTSPEED * gear);
	main->ray.planeY = oldPlaneX * sin(ROTSPEED * gear) + main->ray.planeY
		* cos(ROTSPEED * gear);
}

static void	interactives(t_main *main)
{
	if ((int)main->ray.posX == main->flnf.dist[1][0]
		&& (int)main->ray.posY == main->flnf.dist[1][1])
	{
		if (main->flnf.aux_tp == 70)
		{
			main->ray.posX = (float)main->flnf.dist[0][0] + 0.5;
			main->ray.posY = (float)main->flnf.dist[0][1] + 0.5;
			main->flnf.aux_tp = 1;
			main->ply.ship = 0;
		}
	}
	else if ((int)main->ray.posX == main->flnf.dist[0][0]
		&& (int)main->ray.posY == main->flnf.dist[0][1])
	{
		if (main->flnf.aux_tp == 70)
		{
			main->ray.posX = (float)main->flnf.dist[1][0] + 0.5;
			main->ray.posY = (float)main->flnf.dist[1][1] + 0.5;
			main->flnf.aux_tp = 1;
			main->ply.ship = 0;
		}
	}
	else if (main->flnf.aux_tp < 70 && main->flnf.aux_tp != 0)
		main->flnf.aux_tp++;
}

void	moving_ply(t_main *main)
{
	if (!main->ply.ship)
	{
		if (main->key.move_forward)
			moving_forwback(main, 1);
		if (main->key.move_back)
			moving_forwback(main, -1);
		if (main->key.move_right)
			moving_lerigt(main, 1);
		if (main->key.move_left)
			moving_lerigt(main, -1);
		if (main->key.look_right)
			looking_for_love(main, -1);
		if (main->key.look_left)
			looking_for_love(main, 1);
	}
	else
		moving_ship(main);
	interactives(main);
}
