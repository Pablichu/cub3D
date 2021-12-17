/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_reader.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 18:07:05 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 13:27:53 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub.h"

static void	setting_up_matrix(t_map *flnf)
{
	int	i;

	flnf->map = (char **)malloc(sizeof(char *) * flnf->mpln);
	if (!flnf->map)
		raycast_error(5, NULL, 0);
	i = 0;
	while (i < flnf->mpln)
	{
		flnf->map[i] = (char *)malloc(sizeof(char) * flnf->len + 1);
		if (!flnf->map[i])
			raycast_error(5, NULL, 0);
		i++;
	}
}

static void	hey_matrix_take_this(t_list *auxlst, t_map *flnf, int i)
{
	int	aux;

	aux = ft_strlen(auxlst->content);
	if (aux != flnf->len)
	{
		ft_strlcpy(flnf->map[i], auxlst->content, ++aux);
		aux--;
		while (aux < flnf->len)
		{
			flnf->map[i][aux] = ' ';
			aux++;
		}
		flnf->map[i][flnf->len] = '\0';
	}
	else
		ft_strlcpy(flnf->map[i], auxlst->content, flnf->len + 1);
}

static void	badabum_lst_to_matrix(t_map *flnf)
{
	int		i;
	t_list	*auxlst;

	setting_up_matrix(flnf);
	i = 0;
	auxlst = flnf->maplst;
	while (i < flnf->mpln)
	{
		hey_matrix_take_this(auxlst, flnf, i);
		auxlst = auxlst->next;
		i++;
	}
	ft_lstclear(&flnf->maplst, clear_map_line);
}

void	file_reader(int fd, t_map *flnf)
{
	char	*buff;

	if (fd > 0)
	{
		while (flnf->aux != 255 && reading(fd, &buff) > 0)
		{
			flnf->ln++;
			if (*buff)
			{
				if (!file_conf(buff, flnf))
					file_error(1, flnf->ln, fd);
			}
			free(buff);
		}
		buff = until_map_nothing(fd, buff, flnf);
		taking_map(fd, buff, flnf);
		badabum_lst_to_matrix(flnf);
		basic_check(flnf, 0);
	}
	else
	{
		if (!fd)
			close(0);
		file_error(10, 0, fd);
	}
}
