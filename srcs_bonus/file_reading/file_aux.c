/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:37:24 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/30 19:23:21 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

int	reading(int fd, char **buff)
{
	return (get_next_line(fd, buff));
}

static void	teleporter(t_map *flnf, int x, int y)
{
	if (!flnf->aux_tp)
	{
		flnf->dist[0][0] = x;
		flnf->dist[0][1] = y;
	}
	else if (flnf->aux_tp == 1)
	{
		flnf->dist[1][0] = x;
		flnf->dist[1][1] = y;
	}
	else
		file_error(7, 0, 0);
	flnf->aux_tp++;
}

void	new_sprite_pos(t_map *flnf, int i, int txt)
{
	t_sprite	*spr;

	spr = malloc(sizeof(t_sprite));
	spr->x = flnf->mpln + 0.5;
	spr->y = i + 0.5;
	spr->txt = txt;
	if (txt == 7)
		teleporter(flnf, flnf->mpln, i);
	flnf->sprNum++;
	ft_lstadd_back(&flnf->sprlst, ft_lstnew(spr));
}

void	check_line_bend(char *ln)
{
	int	i;

	i = 0;
	while (ln[i])
	{
		if (ln[i] != ' ' && ln[i] != '1')
			file_error(11, 0, 0);
		i++;
	}
}

void	clear_map_line(void *content)
{
	free(content);
}
