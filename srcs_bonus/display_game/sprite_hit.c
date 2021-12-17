/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_hit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 15:15:52 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 15:20:04 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	hitted(t_main *main)
{
	main->metroid = fork();
	if (!main->metroid)
	{
		if (main->ply.lives == 1)
			system("afplay ./srcs_bonus/txts/hitted.mp3");
		else
			system("afplay ./srcs_bonus/txts/2hit.mp3");
	}
	else
		system("afplay ./srcs_bonus/txts/hit.mp3");
	exit(0);
}

static void	hit(t_main *main)
{
	main->metroid = fork();
	if (!main->metroid)
		hitted(main);
}

void	hitted_sprite(t_main *main, double sprtX, double sprtY, int *txt)
{
	if (sprtX < 0.5 && sprtX > -0.5 && sprtY < 0.5 && sprtY > -0.5)
	{
		if (*txt == 8)
		{
			hit(main);
			main->ply.lives++;
			*txt = 16;
			if (main->ply.lives == 3)
			{
				main->ply.mode = 2;
				system("pkill afplay");
				call_music(main);
			}
		}
		else if (*txt == 9)
		{
			main->ply.ship = 1;
			*txt = 16;
		}
		else if (*txt == 10)
		{
			main->ply.mode = 3;
			call_music(main);
		}
	}
}
