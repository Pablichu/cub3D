/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:33:21 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 19:35:23 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static int	strchk(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(s2, s1[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	player_looks_what(char c, int *i)
{
	if (c == 'S')
		*i = 1;
	else if (c == 'E')
		*i = 2;
	else if (c == 'W')
		*i = 3;
}

static int	map_checknplayer(const char *s1, int ln, t_map *flnf)
{
	int		i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr("NSEW", s1[i]))
		{
			if (flnf->ply_pos[0])
				file_error(8, ln, 0);
			flnf->ply_pos[0] = flnf->mpln;
			flnf->ply_pos[1] = i;
			player_looks_what(s1[i], &flnf->ply_dir);
		}
		else if (ft_strchr(ALLSPRITES, s1[i]))
			new_sprite_pos(flnf, i, s1[i] - 46);
		if (!ft_strchr(ALLCHARS, s1[i]))
			return (0);
		i++;
	}
	if (flnf->len < i)
		flnf->len = i;
	flnf->mpln++;
	return (1);
}

char	*until_map_nothing(int fd, char *buff, t_map *flnf)
{
	reading(fd, &buff);
	flnf->ln++;
	while (strchk(buff, WHILEMAP))
	{
		if (*buff)
		{
			free(buff);
			file_error(2, flnf->ln, fd);
		}
		else
			free(buff);
		flnf->aux = reading(fd, &buff);
		if (!flnf->aux)
			no_map(0);
		flnf->ln++;
	}
	return (buff);
}

void	taking_map(int fd, char *buff, t_map *flnf)
{
	int	j;

	j = 1;
	while (1)
	{
		if (!*buff)
		{
			free(buff);
			j = 0;
		}
		else if (*buff && !j)
			file_error(3, flnf->ln, fd);
		if (j)
		{
			if (!map_checknplayer(buff, flnf->ln, flnf))
				file_error(4, flnf->ln, fd);
			ft_lstadd_back(&flnf->maplst, ft_lstnew(buff));
		}
		if (flnf->aux <= 0)
			break ;
		flnf->aux = reading(fd, &buff) > 0;
		flnf->ln++;
	}
	if (!flnf->ply_pos[0] || !flnf->ply_pos[1])
		file_error(9, 0, fd);
}
