/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/08 21:11:36 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 15:11:18 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	lets_revive(t_main *main)
{
	if (main->key.space)
	{
		main->ply.mode = 1;
		main->ply.lives = 0;
		main->ray.posX = main->flnf.ply_pos[0] + 0.5;
		main->ray.posY = main->flnf.ply_pos[1] + 0.5;
		main->ply.speed = 0;
		setting_player_dir(main);
		call_music(main);
	}
}

static void	dead(t_main *main)
{
	int				x;
	int				y;
	unsigned int	color;

	mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
		main->txt[14].img, 0, 0);
	x = 0;
	color = create_trgb(main->ply.aux, 0, 0, 0);
	while (x < main->flnf.r[0])
	{
		y = 0;
		while (y < main->flnf.r[1])
		{
			my_mlx_pixel_put(&main->img, x, y, color);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->img.img, 0, 0);
	if (main->ply.aux < 254)
		main->ply.aux += 2;
	lets_revive(main);
}

void	menu(t_main *main)
{
	if (!main->ply.mode)
	{
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->txt[15].img, 0, 0);
		if (main->key.space)
		{
			main->ply.mode = 1;
			call_music(main);
		}
	}
	else if (main->ply.mode == 2)
	{
		dead(main);
	}
	else if (main->ply.mode == 3)
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win, main->txt[17].img,
			main->flnf.r[0] / 2 - 500, main->flnf.r[1] / 2 - 250);
}
