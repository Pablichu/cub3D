/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 20:50:22 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 17:17:59 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

void	selector_texture(t_main *main, char *route, int nb)
{
	int	w;
	int	h;

	main->txt[nb].img = mlx_xpm_file_to_image(main->mlx.mlx, route, &w, &h);
	main->txt[nb].addr = mlx_get_data_addr(main->txt[nb].img,
			&main->txt[nb].bits_per_pixel, &main->txt[nb].line_length,
			&main->txt[nb].endian);
}

void	setting_player_dir(t_main *main)
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

void	init_mlx_and_things(t_main *main)
{
	int	i;

	main->ray.posX = main->flnf.ply_pos[0] + 0.5;
	main->ray.posY = main->flnf.ply_pos[1] + 0.5;
	main->ray.ZBuffer = malloc(sizeof(double *) * main->flnf.r[0]);
	setting_player_dir(main);
	main->mlx.mlx = mlx_init();
	if (!main->mlx.mlx)
		raycast_error(2, main, 0);
	mlx_do_sync(main->mlx.mlx);
	i = 0;
	while (i < 50)
	{
		lstiter_adapted(main, main->flnf.sprlst, distance_from_player);
		i++;
	}
}
