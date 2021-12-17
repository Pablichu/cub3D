/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conf_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 15:35:36 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 19:52:50 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

void	basic_resolution(t_map *flnf)
{
	int	i;

	i = 3;
	if (flnf->r[0] < 100 && flnf->r[0] > 0)
	{
		flnf->r[0] = 100;
		i = 1;
	}
	if (flnf->r[1] < 100 && flnf->r[1] > 0)
	{
		flnf->r[1] = 100;
		i = 1;
	}
	if (flnf->r[0] == 0 || flnf->r[1] == 0)
		i = 2;
	no_map(i);
}

int	going_to_conf(char *buff, t_map *flnf, int mode)
{
	int	fail;

	fail = 0;
	if (mode == 0 && !is_bit_set(flnf->aux, flnf->bit.index[mode]))
		fail = resolution(buff + 2, flnf, 0, 0);
	else if (mode > 0 && mode < 8
		&& !is_bit_set(flnf->aux, flnf->bit.index[mode]))
		fail = path_to_textures(buff, flnf, mode - 1);
	return (fail);
}
