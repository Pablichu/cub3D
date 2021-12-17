/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_events.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 20:01:19 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 20:22:59 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	getting_my_textures(t_main *main)
{
	selector_texture(main, "./srcs_bonus/txts/teleport.xpm", 7);
	selector_texture(main, "./srcs_bonus/txts/mina.xpm", 8);
	selector_texture(main, "./srcs_bonus/txts/starship.xpm", 9);
	selector_texture(main, "./srcs_bonus/txts/jack.xpm", 10);
	selector_texture(main, "./srcs_bonus/txts/monitor.xpm", 11);
	selector_texture(main, "./srcs_bonus/txts/green_box.xpm", 12);
	selector_texture(main, "./srcs_bonus/txts/red_box.xpm", 13);
	selector_texture(main, "./srcs_bonus/txts/you_died.xpm", 14);
	selector_texture(main, "./srcs_bonus/txts/init_menu.xpm", 15);
	selector_texture(main, "./srcs_bonus/txts/nothing.xpm", 16);
	selector_texture(main, "./srcs_bonus/txts/success.xpm", 17);
}

static void	get_textures_in_main(t_main *main)
{
	int	i;
	int	w;
	int	h;

	i = 0;
	while (i < 7)
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
	getting_my_textures(main);
}
//1 = South | 2 = East | 3 = Western old girls | 0 = North

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
		call_music(main);
		mlx_do_key_autorepeatoff(main->mlx.mlx);
		mlx_hook(main->mlx.win, 2, 1L << 0, hi_key, main);
		mlx_hook(main->mlx.win, 3, 1L << 1, bye_key, &main->key);
		mlx_loop_hook(main->mlx.mlx, raycast, main);
		mlx_hook(main->mlx.win, 17, 0L, game_close, main);
		mlx_loop(main->mlx.mlx);
	}
}
