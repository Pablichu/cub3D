/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_conf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 20:12:16 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 18:56:10 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

int	resolution(char *buff, t_map *flnf, int i, int j)
{
	int		aux;
	char	*nb;

	while (i < 2)
	{
		while (ft_isspace(buff[j]))
			j++;
		if (!ft_isdigit(buff[j]))
			return (0);
		aux = j;
		while (ft_isdigit(buff[aux]))
			aux++;
		nb = ft_substr(buff + j, 0, aux);
		if (!nb)
			return (0);
		flnf->r[i] = ft_atoi(nb);
		free(nb);
		i++;
		j = aux;
	}
	if (buff[j])
		return (0);
	return (1);
}

int	path_to_textures(char *buff, t_map *flnf, int mode)
{
	int	i;
	int	aux;

	i = 0;
	if (mode == 4)
		buff += 2;
	else
		buff += 3;
	while (ft_isspace(buff[i]))
		i++;
	aux = ft_strlen(buff + i);
	flnf->txts[mode] = ft_substr(buff, i, aux);
	if (!flnf->txts[mode])
		return (0);
	return (1);
}

int	get_rgb(char *buff, int *c, int i, int j)
{
	int		aux;
	char	*nb;

	while (i < 3)
	{
		while (ft_isspace(buff[j]))
			j++;
		if (!ft_isdigit(buff[j]))
			return (0);
		aux = j;
		while (ft_isdigit(buff[aux]) || buff[aux] == 54
			|| ft_isspace(buff[aux]))
			aux++;
		nb = ft_substr(buff + j, 0, aux);
		if (!nb)
			return (0);
		c[i] = ft_atoi(nb);
		free(nb);
		i++;
		j = ++aux;
	}
	if (buff[j - 1])
		return (0);
	return (1);
}

static int	elem_check(int t, char *buff, t_map *flnf, int mode)
{
	int	fail;

	if (!t)
	{
		fail = going_to_conf(buff, flnf, mode);
		if (!fail)
			return (0);
		flnf->aux = set_bit(flnf->aux, flnf->bit.index[mode]);
		return (2);
	}
	return (1);
}

int	file_conf(char *buff, t_map *flnf)
{
	int	i;

	i = 0;
	i += elem_check(ft_strncmp("R ", buff, 2), buff, flnf, 0);
	i += elem_check(ft_strncmp("NO ", buff, 3), buff, flnf, 1);
	i += elem_check(ft_strncmp("SO ", buff, 3), buff, flnf, 2);
	i += elem_check(ft_strncmp("WE ", buff, 3), buff, flnf, 3);
	i += elem_check(ft_strncmp("EA ", buff, 3), buff, flnf, 4);
	i += elem_check(ft_strncmp("S ", buff, 2), buff, flnf, 5);
	i += elem_check(ft_strncmp("F ", buff, 2), buff, flnf, 6);
	i += elem_check(ft_strncmp("C ", buff, 2), buff, flnf, 7);
	if (i < 9)
		return (0);
	return (1);
}
