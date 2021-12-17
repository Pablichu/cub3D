/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bmp_begins.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 19:06:43 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/26 20:23:28 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static void	init_bmp(int fd, t_main *main)
{
	unsigned char	headder[54];
	int				aux;

	aux = 54 + 4 *(main->flnf.r[0] * main->flnf.r[1]);
	ft_bzero(headder, 54);
	headder[0] = 'B';
	headder[1] = 'M';
	headder[2] = (unsigned char)aux;
	headder[3] = (unsigned char)(aux >> 8);
	headder[4] = (unsigned char)(aux >> 16);
	headder[5] = (unsigned char)(aux >> 24);
	headder[10] = (unsigned char)(54);
	headder[14] = (unsigned char)(40);
	headder[18] = (unsigned char)(main->flnf.r[0]);
	headder[19] = (unsigned char)(main->flnf.r[0] >> 8);
	headder[20] = (unsigned char)(main->flnf.r[0] >> 16);
	headder[21] = (unsigned char)(main->flnf.r[0] >> 24);
	headder[22] = (unsigned char)(main->flnf.r[1]);
	headder[23] = (unsigned char)(main->flnf.r[1] >> 8);
	headder[24] = (unsigned char)(main->flnf.r[1] >> 16);
	headder[25] = (unsigned char)(main->flnf.r[1] >> 24);
	headder[26] = (unsigned char)1;
	headder[28] = (unsigned char)32;
	write(fd, headder, 54);
}

static void	write_bmp(int fd, t_main *main)
{
	int				x;
	int				y;
	unsigned int	color;

	y = main->flnf.r[1] - 1;
	while (y >= 0)
	{
		x = 0;
		while (x < main->flnf.r[0])
		{
			color = my_mlx_get_pixel(&main->img, x, y);
			write(fd, &color, 4);
			x++;
		}
		y--;
	}
}

void	create_bmp(t_main *main)
{
	int	fd;

	fd = open("./screenshot.bmp", O_WRONLY | O_CREAT | O_TRUNC
			| O_APPEND, 0755);
	if (fd < 0)
		raycast_error(1, main, 0);
	raycast(main);
	init_bmp(fd, main);
	write_bmp(fd, main);
	close(fd);
	mlx_destroy_window(main->mlx.mlx, main->mlx.win);
}
