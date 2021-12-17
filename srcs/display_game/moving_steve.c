/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moving_steve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:33:54 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/27 17:02:21 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static void	moving_forwback(t_main *main, int gear)
{
	if (main->flnf.map[(int)(main->ray.posX + (main->ray.dirX * MVSPEED
				* gear))][(int)main->ray.posY] != '1')
		main->ray.posX += (main->ray.dirX * MVSPEED * gear);
	if (main->flnf.map[(int)main->ray.posX][(int)(main->ray.posY
		+ (main->ray.dirY * MVSPEED * gear))] != '1')
		main->ray.posY += (main->ray.dirY * MVSPEED * gear);
}

static void	moving_lerigt(t_main *main, int gear)
{
	if (main->flnf.map[(int)(main->ray.posX + (main->ray.planeX * MVSPEED
				* gear))][(int)main->ray.posY] != '1')
		main->ray.posX += (main->ray.planeX * MVSPEED * gear);
	if (main->flnf.map[(int)main->ray.posX][(int)(main->ray.posY
		+ (main->ray.planeY * MVSPEED * gear))] != '1')
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

void	moving_ply(t_main *main)
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
