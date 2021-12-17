/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 20:11:42 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 16:05:20 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"h_cub_bonus.h"

static void	set_bit_index(t_bitindex *bits)
{
	bits->index[0] = 0x001;
	bits->index[1] = 0x002;
	bits->index[2] = 0x004;
	bits->index[3] = 0x008;
	bits->index[4] = 0x010;
	bits->index[5] = 0x020;
	bits->index[6] = 0x040;
	bits->index[7] = 0x080;
}

static void	display_results(t_map *flnf)
{
	int	i;

	i = 0;
	printf(GREEN "SMOKING SICK MAP\n" RESET);
	while (i < flnf->mpln)
	{
		printf(WHITE_BOX_BLUE "%s" RESET "\n", flnf->map[i]);
		i++;
	}
	printf(GRAY "\nRESOLUTION" WHITE_CURS " x = %d / y = %d", flnf->r[0],
		flnf->r[1]);
	printf(YELLOW "\nPATHS" RESET);
	printf("   NO = |%s|\n\tSO = |%s|\n\tWE = |%s|\n\tEA = |%s|",
		flnf->txts[0], flnf->txts[1], flnf->txts[2], flnf->txts[3]);
	printf(CYAN "\nSPRITE" RESET "\t = |%s|", flnf->txts[4]);
	printf(BLUE "\nFLOAR" RESET "\t = |%s|", flnf->txts[5]);
	printf(PURPLE "\nCELLING" RESET "\t = |%s|\n"
		YELLOW "Player position |%.0f -- %.0f|\n", flnf->txts[6],
		flnf->ply_pos[0], flnf->ply_pos[1]);
	printf("Max lenght of line in map: %d\nLines of map: %d\n",
		flnf->len, flnf->mpln);
	printf("There are like " RED "%d" YELLOW " sprites\n" RESET, flnf->sprNum);
}

static int	checking_that_arg(char *args, t_map *flnf, int i)
{
	if (!ft_strncmp(args + (ft_strlen(args) - 6), "--save", 6)
		&& !is_bit_set(flnf->args_mode, flnf->bit.index[0]))
		flnf->args_mode = set_bit(flnf->args_mode, flnf->bit.index[0]);
	else if (!ft_strncmp(args + (ft_strlen(args) - 7), "--leaks", 7)
		&& !is_bit_set(flnf->args_mode, flnf->bit.index[1]))
		flnf->args_mode = set_bit(flnf->args_mode, flnf->bit.index[1]);
	else if (!ft_strncmp(args + (ft_strlen(args) - 6), "--kato", 6)
		&& !is_bit_set(flnf->args_mode, flnf->bit.index[2]))
		flnf->args_mode = set_bit(flnf->args_mode, flnf->bit.index[2]);
	else if (!ft_strncmp(args + (ft_strlen(args) - 7), "--parse", 7)
		&& !is_bit_set(flnf->args_mode, flnf->bit.index[4]))
		flnf->args_mode = set_bit(flnf->args_mode, flnf->bit.index[4]);
	else if (!ft_strncmp(args + (ft_strlen(args) - 6), "--file", 6)
		&& !is_bit_set(flnf->args_mode, flnf->bit.index[5]))
		flnf->args_mode = set_bit(flnf->args_mode, flnf->bit.index[5]);
	else if (!ft_strncmp(args + (ft_strlen(args) - 4), ".cub", 4)
		&& i == 1)
		flnf->args_mode = set_bit(flnf->args_mode, flnf->bit.index[3]);
	else
		return (1);
	return (0);
}

static int	args_manage(int ar, char **args, t_map *flnf, int i)
{
	while (i < ar)
	{
		if (checking_that_arg(args[i], flnf, i))
		{
			if (!ft_strncmp(args[i], "--", 2))
			{
				printf("Error\n" RED "(%s) is not a valid argument\n", args[i]);
				exit(0);
			}
			else if (is_bit_set(flnf->args_mode, flnf->bit.index[3]))
			{
				printf("Error\n" RED "(%s) is not .cub format\n", args[i]);
				exit(0);
			}
		}
		i++;
	}
	if (!is_bit_set(flnf->args_mode, flnf->bit.index[3]))
	{
		printf("Error\n" RED "The first argument has to be .cub\n");
		return (0);
	}
	return (1);
}

int	main(int ar, char **args)
{
	t_main	main;
	int		fd;

	if (ar > 1)
	{
		ft_bzero(&main, sizeof(t_main));
		set_bit_index(&main.flnf.bit);
		if (args_manage(ar, args, &main.flnf, 1))
		{
			fd = open(args[1], O_RDONLY);
			file_reader(fd, &main.flnf);
			close(fd);
			if (is_bit_set(main.flnf.args_mode, main.flnf.bit.index[2]))
				kato();
			if (is_bit_set(main.flnf.args_mode, main.flnf.bit.index[5]))
				display_results(&main.flnf);
			hooks_or_bmp(&main);
		}	
	}
	else
		printf("Error\n" RED "Ur mom does not support u\n"
			"Put a map and maybe she would\n" RED);
	return (0);
}
