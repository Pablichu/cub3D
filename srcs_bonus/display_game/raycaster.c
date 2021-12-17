/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 19:39:26 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/17 17:19:58 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	printing_world(t_main *main, int drawStart, int drawEnd, int x)
{
	int		texY;
	char	*dst;

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
}

void	call_music(t_main *main)
{
	main->metroid = fork();
	if (!main->metroid)
	{
		if (main->ply.lives == 3)
			system("afplay ./srcs_bonus/txts/YOU_DIED.mp3");
		else if (main->ply.mode == 3)
		{
			system("pkill afplay");
			system("afplay ./srcs_bonus/txts/mario_success.mp3");
		}
		else if (main->ply.mode == 0)
			system("afplay ./srcs_bonus/txts/init_music.mp3");
		else
		{
			system("pkill afplay");
			system("afplay ./srcs_bonus/txts/Super_Metroid.mp3");
		}
		exit(0);
	}
}

static void	walls_caster(t_main *main)
{
	double	perpWallDist;
	int		drawStart;
	int		drawEnd;
	int		x;

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
}

int	raycast(t_main *main)
{
	if (main->ply.mode == 1)
	{
		floor_caster(main);
		walls_caster(main);
		sprites_going_in(main);
		mlx_put_image_to_window(main->mlx.mlx, main->mlx.win,
			main->img.img, 0, 0);
		hud(main);
		moving_ply(main);
	}
	else
		menu(main);
	return (0);
}
