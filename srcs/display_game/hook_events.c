/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:01:19 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 17:16:43 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	get_textures_in_main(t_main *main)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < 5)
	{
		main->txt[i].img = mlx_xpm_file_to_image(main->mlx.mlx,
				main->flnf.txts[i], &w, &h);
		if (!main->txt[i].img)
			raycast_error(3, main, i);
		if (w != 64 || h != 64)
			raycast_error(4, main, i);
		main->txt[i].addr = mlx_get_data_addr(main->txt[i].img,
				&main->txt[i].bits_per_pixel, &main->txt[i].line_length,
				&main->txt[i].endian);
		i++;
	}
}
//1 = South | 2 = East | 3 = Western old girls | 0 = North

static void	setting_player_dir(t_main *main)
{
	if (main->flnf.ply_dir == 1)
	{
		main->ray.dirX = 1;
		main->ray.planeY = -0.66;
	}
	else if (main->flnf.ply_dir == 2)
	{
		main->ray.dirY = 1;
		main->ray.planeX = 0.66;
	}
	else if (main->flnf.ply_dir == 3)
	{
		main->ray.dirY = -1;
		main->ray.planeX = -0.66;
	}
	else
	{
		main->ray.dirX = -1;
		main->ray.planeY = 0.66;
	}
}

static void	init_mlx_and_things(t_main *main)
{
	int	i;

	main->ray.posX = main->flnf.ply_pos[0] + 0.5;
	main->ray.posY = main->flnf.ply_pos[1] + 0.5;
	main->flnf.floor = create_trgb(0, main->flnf.f[0],
			main->flnf.f[1], main->flnf.f[2]);
	main->flnf.celen = create_trgb(0, main->flnf.c[0],
			main->flnf.c[1], main->flnf.c[2]);
	main->ray.ZBuffer = malloc(sizeof(double *) * main->flnf.r[0]);
	setting_player_dir(main);
	main->mlx.mlx = mlx_init();
	if (!main->mlx.mlx)
		raycast_error(2, main, 0);
	i = 0;
	while (i < 50)
	{
		lstiter_adapted(main, main->flnf.sprlst, distance_from_player);
		i++;
	}
}

void	hooks_or_bmp(t_main *main)
{
	please_not_much_resolution(main);
	init_mlx_and_things(main);
	get_textures_in_main(main);
	main->mlx.win = mlx_new_window(main->mlx.mlx, main->flnf.r[0],
			main->flnf.r[1], "cub3D");
	main->img.img = mlx_new_image(main->mlx.mlx, main->flnf.r[0],
			main->flnf.r[1]);
	main->img.addr = mlx_get_data_addr(main->img.img, &main->img.bits_per_pixel,
			&main->img.line_length, &main->img.endian);
	if (is_bit_set(main->flnf.args_mode, main->flnf.bit.index[0]))
		create_bmp(main);
	else
	{
		mlx_do_key_autorepeatoff(main->mlx.mlx);
		mlx_hook(main->mlx.win, 2, 1L << 0, hi_key, main);
		mlx_hook(main->mlx.win, 3, 1L << 1, bye_key, &main->key);
		mlx_loop_hook(main->mlx.mlx, raycast, main);
		mlx_hook(main->mlx.win, 17, 0L, game_close, main);
		mlx_loop(main->mlx.mlx);
	}
}
