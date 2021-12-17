/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 12:26:44 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:02:14 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_libft.h"

static char	*file_upgrade(char *file, char **line, int len)
{
	char			*aux;
	unsigned int	i;

	i = 0;
	while (file[i] != '\n' && file[i])
		i++;
	if (i < ft_strlen(file))
	{
		*line = ft_substr(file, 0, i);
		aux = ft_substr(file, i + 1, ft_strlen(file));
		free(file);
		file = ft_strdup(aux);
		free(aux);
	}
	else if (len == 0)
	{
		*line = file;
		file = NULL;
	}
	return (file);
}

static char	*jump(char *file, char *ln, int len)
{
	char	*aux;

	ln[len] = '\0';
	if (file)
	{
		aux = ft_strjoin(file, ln);
		free(file);
		file = ft_strdup(aux);
		free(aux);
	}
	else
		file = ft_strdup(ln);
	return (file);
}

int	get_next_line(int fd, char **line)
{
	static char	*file[256];
	int			len;
	char		ln[515];

	if (fd < 0 || fd > 256 || !line)
		return (-1);
	len = read(fd, ln, 514);
	while (len)
	{
		if (len == -1)
			return (-1);
		file[fd] = jump(file[fd], ln, len);
		if (ft_strchr(ln, '\n'))
			break ;
		len = read(fd, ln, 514);
	}
	if (len <= 0 && !file[fd])
	{
		*line = ft_strdup("");
		return (len);
	}
	file[fd] = file_upgrade(file[fd], line, len);
	if (len <= 0 && !file[fd])
		return (len);
	return (1);
}
