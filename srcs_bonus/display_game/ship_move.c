/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ship_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 20:33:54 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 20:09:30 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static double	moving_forwback(t_main *main, double gear)
{
	int	aux;

	aux = 0;
	if (!ft_strchr("12", main->flnf.map[(int)(main->ray.posX + (main->ray.dirX
					* gear))][(int)main->ray.posY]))
		main->ray.posX += (main->ray.dirX * gear);
	else
		aux++;
	if (!ft_strchr("12", main->flnf.map[(int)main->ray.posX][
			(int)(main->ray.posY + (main->ray.dirY * gear))]))
		main->ray.posY += (main->ray.dirY * gear);
	else
		aux++;
	if (aux == 2)
		return (0.0);
	if (aux == 1)
		return (gear / 8.0);
	return (gear);
}

static void	moving_lerigt(t_main *main, int gear)
{
	double	speed;

	speed = MVSPEED - 0.05;
	if (main->ply.lives == 2)
		speed -= 0.03;
	if (!ft_strchr("12", main->flnf.map[(int)(main->ray.posX
				+ (main->ray.planeX * speed * gear))][(int)main->ray.posY]))
		main->ray.posX += (main->ray.planeX * speed * gear);
	if (!ft_strchr("12", main->flnf.map[(int)main->ray.posX][
			(int)(main->ray.posY + (main->ray.planeY * speed * gear))]))
		main->ray.posY += (main->ray.planeY * speed * gear);
}

static void	looking_for_love(t_main *main, int gear)
{
	double	oldDirX;
	double	oldPlaneX;
	double	speed;

	speed = ROTSPEED - 0.024;
	if (main->ply.lives == 2)
		speed /= 2;
	oldDirX = main->ray.dirX;
	main->ray.dirX = main->ray.dirX * cos(speed * gear) - main->ray.dirY
		* sin(speed * gear);
	main->ray.dirY = oldDirX * sin(speed * gear) + main->ray.dirY
		* cos(speed * gear);
	oldPlaneX = main->ray.planeX;
	main->ray.planeX = main->ray.planeX * cos(speed * gear)
		- main->ray.planeY * sin(speed * gear);
	main->ray.planeY = oldPlaneX * sin(speed * gear) + main->ray.planeY
		* cos(speed * gear);
}

static void	forward_system(t_main *main)
{
	if (main->key.move_forward)
		main->ply.speed += 0.0025;
	else if (main->key.move_back)
		main->ply.speed -= 0.002;
	if (main->ply.speed > 0.0 && !main->key.move_forward)
		main->ply.speed -= 0.001;
	if (main->ply.speed < 0.0 && !main->key.move_back)
		main->ply.speed -= 0.001;
	if (main->ply.speed > 0.0)
	{
		if (main->ply.speed > 0.45 && main->ply.lives == 0)
			main->ply.speed = 0.45;
		else if (main->ply.speed > 0.8)
			main->ply.speed = 0.8;
	}
	else if (main->ply.speed < 0.0)
	{
		if (main->ply.speed < -0.02)
			main->ply.speed = -0.02;
	}
	main->ply.speed = moving_forwback(main, main->ply.speed);
}

void	moving_ship(t_main *main)
{
	forward_system(main);
	if (main->key.move_right)
		moving_lerigt(main, 1);
	if (main->key.move_left)
		moving_lerigt(main, -1);
	if (main->key.look_right)
		looking_for_love(main, -1);
	if (main->key.look_left)
		looking_for_love(main, 1);
}
