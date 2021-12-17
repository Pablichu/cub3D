/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:39:26 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/27 13:23:22 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static void	little_floor_loop(t_main *main, int begin, int end, int x)
{
	while (begin < end)
	{
		main->inf.dst = main->img.addr + (begin * main->img.line_length + x
				* (main->img.bits_per_pixel / 8));
		*(unsigned int *)main->inf.dst = main->flnf.floor;
		begin++;
	}
}

static void	little_ceilling_loop(t_main *main, int begin, int end, int x)
{
	while (begin < end)
	{
		main->inf.dst = main->img.addr + (begin * main->img.line_length + x
				* (main->img.bits_per_pixel / 8));
		*(unsigned int *)main->inf.dst = main->flnf.celen;
		begin++;
	}
}

static void	printing_world(t_main *main, int drawStart, int drawEnd, int x)
{
	int		texY;
	char	*dst;

	little_ceilling_loop(main, 0, drawStart, x);
	while (drawStart <= drawEnd)
	{
		texY = (int)main->inf.texPos & (SF - 1);
		main->inf.texPos += main->inf.step;
		dst = main->img.addr + (drawStart * main->img.line_length + x
				* (main->img.bits_per_pixel / 8));
		*(unsigned int *)dst = my_mlx_get_pixel(&main->txt[main->inf.texNum],
				main->inf.texX, texY);
		drawStart++;
	}
	little_floor_loop(main, drawEnd + 1, main->flnf.r[1], x);
}

int	raycast(t_main *main)
{
	double	perpWallDist;
	int		drawStart;
	int		drawEnd;
	int		x;

	moving_ply(main);
	x = 0;
	while (x < main->flnf.r[0])
	{
		init_variables(main, x);
		calculating_sides(main, &perpWallDist, x);
		checking_hit(main, perpWallDist, &drawEnd, &drawStart);
		texture_select(main);
		printing_world(main, drawStart, drawEnd, x);
		x++;
	}
	sprites_going_in(main);
	mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->img.img, 0, 0);
	return (0);
}
