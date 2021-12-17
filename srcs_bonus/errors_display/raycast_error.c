/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 19:04:17 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/29 20:55:45 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

#define ERR_OPEN_FAIL "It was impossible to create a bmp\n"
#define ERR_INIT_FAIL "Couln't open an mlx graphic address\n"
#define ERR_XPM_NOTVL "is not a valid xpm or couldn't open it\n"
#define ERR_XPM_NOT64 "has to be 64 * 64\n"
#define ERR_BAD_MESET "Couldn't assign memory. I mean like malloc fucked up\n"

void	raycast_error(int type, t_main *main, int i)
{
	printf("Error\n");
	if (type == 1)
		printf(RED "%s" RESET, ERR_OPEN_FAIL);
	else if (type == 2)
		printf(RED "%s" RESET, ERR_INIT_FAIL);
	else if (type == 3)
		printf(RED "%s %s", main->flnf.txts[i], ERR_XPM_NOTVL);
	else if (type == 4)
		printf(RED "%s %s", main->flnf.txts[i], ERR_XPM_NOT64);
	else if (type == 5)
		printf(RED "%s" RESET, ERR_BAD_MESET);
	if (is_bit_set(main->flnf.args_mode, main->flnf.bit.index[1]))
		system("leaks cub3D");
	exit(type);
}
