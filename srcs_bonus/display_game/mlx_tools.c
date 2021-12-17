/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 16:24:52 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/07 20:20:46 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

int	game_close(t_main *main)
{
	mlx_destroy_window(main->mlx.mlx, main->mlx.win);
	if (is_bit_set(main->flnf.args_mode, main->flnf.bit.index[1]))
		system("leaks cub3D");
	system("pkill afplay");
	exit(0);
}

int	hi_key(int keycode, t_main *main)
{
	if (keycode == K_W)
		main->key.move_forward = 1;
	else if (keycode == K_S)
		main->key.move_back = 1;
	else if (keycode == K_A)
		main->key.move_left = 1;
	else if (keycode == K_D)
		main->key.move_right = 1;
	else if (keycode == K_LEFT)
		main->key.look_left = 1;
	else if (keycode == K_RIGHT)
		main->key.look_right = 1;
	else if (keycode == K_SPACE)
		main->key.space = 1;
	else if (keycode == K_ESC)
		game_close(main);
	return (0);
}

int	bye_key(int keycode, t_keys *key)
{
	if (keycode == K_W)
		key->move_forward = 0;
	else if (keycode == K_S)
		key->move_back = 0;
	else if (keycode == K_A)
		key->move_left = 0;
	else if (keycode == K_D)
		key->move_right = 0;
	else if (keycode == K_LEFT)
		key->look_left = 0;
	else if (keycode == K_RIGHT)
		key->look_right = 0;
	else if (keycode == K_SPACE)
		key->space = 0;
	return (0);
}

void	please_not_much_resolution(t_main *main)
{
	if (!is_bit_set(main->flnf.args_mode, main->flnf.bit.index[0])
		|| main->flnf.r[0] < 0 || main->flnf.r[1] < 0)
	{
		if (main->flnf.r[0] > MAX_X || main->flnf.r[0] < 0)
			main->flnf.r[0] = MAX_X;
		if (main->flnf.r[1] > MAX_Y || main->flnf.r[1] < 0)
			main->flnf.r[1] = MAX_Y;
	}
}
