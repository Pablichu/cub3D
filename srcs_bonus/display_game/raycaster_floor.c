/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_floor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 20:24:53 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 15:54:12 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	printing_skyor(t_main *main, int y, float floorX, float floorY)
{
	int		tx;
	int		ty;
	int		x;
	char	*dst;

	x = 0;
	while (x < main->flnf.r[0])
	{
		tx = (int)(SF * (floorX - (float)((int)(floorX)))) & (SF - 1);
		ty = (int)(SF * (floorY - (float)((int)(floorY)))) & (SF - 1);
		floorX += main->skor.flStpX;
		floorY += main->skor.flStpY;
		dst = main->img.addr + (y * main->img.line_length + x
				* (main->img.bits_per_pixel / 8));
		*(unsigned int *)dst = my_mlx_get_pixel(&main->txt[4], tx, ty);
		dst = main->img.addr + ((main->flnf.r[1] - y - 1)
				* main->img.line_length + x * (main->img.bits_per_pixel / 8));
		*(unsigned int *)dst = my_mlx_get_pixel(&main->txt[5], tx, ty);
		++x;
	}
}

static void	init_casting(t_main *main, int y)
{
	float	floorX;
	float	floorY;

	main->skor.ryDX0 = main->ray.dirX - main->ray.planeX;
	main->skor.ryDY0 = main->ray.dirY - main->ray.planeY;
	main->skor.ryDX1 = main->ray.dirX + main->ray.planeX;
	main->skor.ryDY1 = main->ray.dirY + main->ray.planeY;
	main->skor.rowD = (0.5 * main->flnf.r[1]) / (y - main->flnf.r[1] / 2);
	main->skor.flStpX = main->skor.rowD
		* (main->skor.ryDX1 - main->skor.ryDX0) / main->flnf.r[0];
	main->skor.flStpY = main->skor.rowD
		* (main->skor.ryDY1 - main->skor.ryDY0) / main->flnf.r[0];
	floorX = main->ray.posX + main->skor.rowD * main->skor.ryDX0;
	floorY = main->ray.posY + main->skor.rowD * main->skor.ryDY0;
	printing_skyor(main, y, floorX, floorY);
}

void	floor_caster(t_main *main)
{
	int		y;

	y = main->flnf.r[1] / 2 + 1;
	while (y < main->flnf.r[1])
	{
		init_casting(main, y);
		++y;
	}
}
