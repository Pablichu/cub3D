/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_put.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/20 20:20:20 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 13:25:49 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static void	init_sprite_info(t_main *main, t_sprite *auxstr, double	*transformY)
{
	double	spriteX;
	double	spriteY;
	double	invDet;
	double	transformX;

	spriteX = auxstr->x - main->ray.posX;
	spriteY = auxstr->y - main->ray.posY;
	invDet = 1.0 / (main->ray.planeX * main->ray.dirY - main->ray.dirX
			* main->ray.planeY);
	transformX = invDet * (main->ray.dirY * spriteX - main->ray.dirX
			* spriteY);
	*transformY = invDet * (-main->ray.planeY * spriteX + main->ray.planeX
			* spriteY);
	main->spr.sprScrnX = (int)((main->flnf.r[0] / 2) * (1 + transformX
				/ *transformY));
	main->spr.vMvScn = (int)(VMOVE / *transformY);
}

static void	computing_pixel_size(t_main *main, double *transformY)
{
	main->spr.dwSrtY = -main->spr.sprHht / 2 + main->flnf.r[1]
		/ 2 + main->spr.vMvScn;
	if (main->spr.dwSrtY < 0)
		main->spr.dwSrtY = 0;
	main->spr.dwEndY = main->spr.sprHht / 2 + main->flnf.r[1]
		/ 2 + main->spr.vMvScn;
	if (main->spr.dwEndY >= main->flnf.r[1])
		main->spr.dwEndY = main->flnf.r[1] - 1;
	main->spr.sprWth = abs((int)(main->flnf.r[1] / (*transformY))) / UDIV;
	main->spr.dwSrtX = -main->spr.sprWth / 2 + main->spr.sprScrnX;
	if (main->spr.dwSrtX < 0)
		main->spr.dwSrtX = 0;
	main->spr.dwEndX = main->spr.sprWth / 2 + main->spr.sprScrnX;
	if (main->spr.dwEndX >= main->flnf.r[0])
		main->spr.dwEndX = main->flnf.r[0] - 1;
}

static void	printing(t_img *img, int stripe, int y, unsigned int color)
{
	char	*dst;

	if ((color & 0x00FFFFFF) != 0)
	{
		dst = img->addr + (y * img->line_length + stripe
				* (img->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

static void	sprites_print(t_main *main, t_sprite *auxstr,
	double *transformY, int stripe)
{
	int				y;
	int				texY;
	int				texX;

	while (stripe < main->spr.dwEndX)
	{
		texX = (int)(256 * (stripe - (-main->spr.sprWth / 2
						+ main->spr.sprScrnX)) * SF / main->spr.sprWth) / 256;
		if (*transformY > 0 && stripe > 0 && stripe < main->flnf.r[0]
			&& *transformY < main->ray.ZBuffer[stripe])
		{
			y = main->spr.dwSrtY;
			while (y < main->spr.dwEndY)
			{
				texY = ((((y - main->spr.vMvScn) * 256 - main->flnf.r[1] * 128
								+ main->spr.sprHht * 128) * SF)
						/ main->spr.sprHht) / 256;
				printing(&main->img, stripe, y,
					my_mlx_get_pixel(&main->txt[auxstr->txt], texX, texY));
				y++;
			}
		}
		stripe++;
	}
}

void	sprites_going_in(t_main *main)
{
	t_list			*auxlst;
	t_sprite		*auxstr;
	double			transformY;
	int				i;

	lstiter_adapted(main, main->flnf.sprlst, distance_from_player);
	auxlst = main->flnf.sprlst;
	i = 0;
	while (i < main->flnf.sprNum)
	{
		auxstr = auxlst->content;
		init_sprite_info(main, auxstr, &transformY);
		main->spr.sprHht = abs((int)(main->flnf.r[1] / (transformY))) / VDIV;
		computing_pixel_size(main, &transformY);
		sprites_print(main, auxstr, &transformY, main->spr.dwSrtX);
		auxlst = auxlst->next;
		i++;
	}
}
