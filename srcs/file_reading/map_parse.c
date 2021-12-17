/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/17 23:56:11 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/17 23:56:11 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static void	beside_nothing(t_map *flnf, int i, int j)
{
	int	fail;

	fail = 0;
	if ((flnf->map[i][j + 1] != '1' && flnf->map[i][j + 1] != ' ')
		|| (flnf->map[i + 1][j] != '1' && flnf->map[i + 1][j] != ' '))
		fail++;
	if (flnf->map[i + 1][j] == '1' && flnf->map[i][j + 1] == '1'
		&& flnf->map[i + 1][j + 1] != '1' && flnf->map[i + 1][j + 1] != ' ')
		fail++;
	if (fail)
	{
		flnf->map[i][j] = 'X';
		map_parse_error(flnf, i, j, is_bit_set(flnf->args_mode,
				flnf->bit.index[4]));
	}
}

static void	beside_wall(t_map *flnf, int i, int j)
{
	int	fail;

	fail = 0;
	if ((flnf->map[i][j + 1] != '1' && flnf->map[i][j + 1] != ' ')
		&& flnf->map[i + 1][j] == ' ')
		fail++;
	if ((flnf->map[i + 1][j] != '1' && flnf->map[i + 1][j] != ' ')
		&& flnf->map[i][j + 1] == ' ')
		fail++;
	if (fail)
	{
		flnf->map[i][j] = 'X';
		map_parse_error(flnf, i, j, is_bit_set(flnf->args_mode,
				flnf->bit.index[4]));
	}
}

static void	beside_things(t_map *flnf, int i, int j)
{
	int	fail;

	fail = 0;
	if (flnf->map[i + 1][j] == ' ' || flnf->map[i][j + 1] == ' ')
		fail++;
	if (flnf->map[i + 1][j] == '1' && flnf->map[i][j + 1] == '1'
		&& flnf->map[i + 1][j + 1] == ' ')
		fail++;
	if ((j == 0 || j == (flnf->len - 1))
		&& (flnf->map[i][j] != ' ' && flnf->map[i][j] != '1'))
		fail++;
	if (fail)
	{
		flnf->map[i][j] = 'X';
		map_parse_error(flnf, i, j, is_bit_set(flnf->args_mode,
				flnf->bit.index[4]));
	}
}

void	map_parse(t_map *flnf)
{
	int	i;
	int	j;

	i = 0;
	check_line_bend(flnf->map[i]);
	while (i < (flnf->mpln - 1))
	{
		j = 0;
		while (j < flnf->len - 1)
		{
			if (flnf->map[i][j] == ' ')
				beside_nothing(flnf, i, j);
			else if (flnf->map[i][j] == '1')
				beside_wall(flnf, i, j);
			else
				beside_things(flnf, i, j);
			j++;
		}
		i++;
	}
	check_line_bend(flnf->map[i]);
}

void	basic_check(t_map *flnf, int i)
{
	basic_resolution(flnf);
	while (i < 5)
	{
		flnf->aux = open(flnf->txts[i], O_RDONLY);
		if (flnf->aux < 0)
		{
			close(flnf->aux);
			file_error(6, 0, 0);
		}
		close(flnf->aux);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		if (!(flnf->c[i] >= 0 && flnf->c[i] <= 255)
			|| !(flnf->f[i] >= 0 && flnf->f[i] <= 255))
			file_error(7, 0, 0);
		i++;
	}
	map_parse(flnf);
}
