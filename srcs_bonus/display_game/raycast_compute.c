/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_compute.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 19:29:26 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/29 20:53:03 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

void	init_variables(t_main *main, int x)
{
	double	cameraX;

	cameraX = 2 * x / (double)main->flnf.r[0] - 1;
	main->inf.rayDirX = main->ray.dirX + main->ray.planeX * cameraX;
	main->inf.rayDirY = main->ray.dirY + main->ray.planeY * cameraX;
	main->inf.mapX = (int)main->ray.posX;
	main->inf.mapY = (int)main->ray.posY;
	main->ray.deltaDistX = fabs(1 / main->inf.rayDirX);
	main->ray.deltaDistY = fabs(1 / main->inf.rayDirY);
}

void	calculating_sides(t_main *main, double *perpWallDist, int x)
{
	int	stepX;
	int	stepY;

	stepX = calculating_stepX(main);
	stepY = calculating_stepY(main);
	checking_wall_hit(main, stepX, stepY);
	if (main->inf.side == 0)
		*perpWallDist = (main->inf.mapX - main->ray.posX + (1 - stepX) / 2)
			/ main->inf.rayDirX;
	else
		*perpWallDist = (main->inf.mapY - main->ray.posY + (1 - stepY) / 2)
			/ main->inf.rayDirY;
	main->ray.ZBuffer[x] = *perpWallDist;
}

void	checking_wall_hit(t_main *main, int stepX, int stepY)
{
	main->inf.hit = 0;
	while (main->inf.hit == 0)
	{
		if (main->inf.sideDistX < main->inf.sideDistY)
		{
			main->inf.sideDistX += main->ray.deltaDistX;
			main->inf.mapX += stepX;
			main->inf.side = 0;
		}
		else
		{
			main->inf.sideDistY += main->ray.deltaDistY;
			main->inf.mapY += stepY;
			main->inf.side = 1;
		}
		if (main->flnf.map[main->inf.mapX][main->inf.mapY] == 49)
			main->inf.hit = 1;
	}
}
//perform DDA??

void	checking_hit(t_main *main, double perpWallDist, int *drawEnd,
			int *drawStart)
{
	double	wallX;
	int		lineHeight;

	lineHeight = (int)(main->flnf.r[1] / perpWallDist);
	*drawStart = -lineHeight / 2 + main->flnf.r[1] / 2;
	if (*drawStart < 0)
		*drawStart = 0;
	*drawEnd = lineHeight / 2 + main->flnf.r[1] / 2;
	if (*drawEnd >= main->flnf.r[1])
		*drawEnd = main->flnf.r[1] - 1;
	if (main->inf.side == 0)
		wallX = main->ray.posY + perpWallDist * main->inf.rayDirY;
	else
		wallX = main->ray.posX + perpWallDist * main->inf.rayDirX;
	wallX -= floor((wallX));
	main->inf.texX = (int)(wallX * (double)(SF));
	if (main->inf.side == 0 && main->inf.rayDirX > 0)
		main->inf.texX = SF - main->inf.texX - 1;
	if (main->inf.side == 1 && main->inf.rayDirY < 0)
		main->inf.texX = SF - main->inf.texX - 1;
	main->inf.step = 1.0 * SF / lineHeight;
	main->inf.texPos = (*drawStart - main->flnf.r[1] / 2 + lineHeight / 2)
		* main->inf.step;
	main->inf.texX = (int)(wallX * (double)(SF));
}
// TODO: an integer-only bresenham or DDA like algorithm could make 
// the texture coordinate stepping faster
