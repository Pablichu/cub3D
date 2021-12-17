/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 00:38:07 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/03/18 00:38:07 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

#define ERR_BAD_PARAM "Bad written parameter:\n\t  Repeated or incorrect\n"
#define ERR_BAD_CHARS "Some inappropriate characters before map\n"
#define ERR_MAP_NFAIL "AFTER MAP THERE CAN'T BE ANYTHING\n"
#define ERR_MAP_CHARS "INVALID CHARACTER IN MAP\n"
#define ERR_LOW_RSLTN "Resolution too low\n"
#define ERR_BAD_PATHR "Path not valid to texture\n"
#define ERR_TOO_MCHTP "There can only be 2 or 0 tp points man...\n"
#define ERR_TOO_MPLYS "There can only be one player\n"
#define ERR_NOT_STPLY "Set the player position man...\n"
#define ERR_BAD_CUBPT "Set a valid .cub path...\nUr mother could love u...\n"
#define ERR_BAD_MAPST "Your map is not close or doesn't meet my standards\n"

void	map_parse_error(t_map *flnf, int i, int j, int parse)
{
	printf(RED "%s", ERR_BAD_MAPST);
	printf("Line \\\\%3d//\nChar \\\\%3d//\n" RESET, (flnf->ln - flnf->mpln + i), j);
	i = 0;
	while (i < flnf->mpln && parse)
	{
		if (ft_strchr(flnf->map[i], 'X'))
		{
			j = 0;
			while (flnf->map[i][j])
			{
				if (flnf->map[i][j] == 'X')
					printf(WHITE_BOX_RED "%c" RESET, flnf->map[i][j]);
				else
					printf(WHITE_BOX_BLUE "%c" RESET, flnf->map[i][j]);
				j++;
			}
			printf("\n");
		}
		else
			printf(WHITE_BOX_BLUE "%s" RESET "\n", flnf->map[i]);
		i++;
	}
	exit(11);
}

void	no_map(int i)
{
	if (!i)
	{
		printf("Error\n");
		printf(RED "Bro... where's the map?\nDid ur mother forget u?\n");
		exit(0);
	}
	if (i == 1)
		printf(YELLOW "Too low resolution\nSetted to mininum resolution\n");
	if (i == 2)
	{
		printf(YELLOW "No Resolution\nNo Game\n");
		exit(0);
	}
}

void	file_error(int type, int ln, int fd)
{
	if (fd > 0)
		close(fd);
	printf("Error\n");
	if (type == 1)
		printf(RED "(Line %d) %s" RESET, ln, ERR_BAD_PARAM);
	else if (type == 2)
		printf(RED "(Line %d) %s" RESET, ln, ERR_BAD_CHARS);
	else if (type == 3)
		printf(RED "(Line %d) %s" RESET, ln, ERR_MAP_NFAIL);
	else if (type == 4)
		printf(RED "(Line %d) %s" RESET, ln, ERR_MAP_CHARS);
	else if (type == 5)
		printf(RED "%s" RESET, ERR_LOW_RSLTN);
	else if (type == 6)
		printf(RED "%s" RESET, ERR_BAD_PATHR);
	else if (type == 7)
		printf(RED "%s" RESET, ERR_TOO_MCHTP);
	else if (type == 8)
		printf(RED "(Line %d) %s" RESET, ln, ERR_TOO_MPLYS);
	else if (type == 9)
		printf(RED "%s" RESET, ERR_NOT_STPLY);
	else if (type == 10)
		printf(RED "%s" RESET, ERR_BAD_CUBPT);
	exit(type);
}
