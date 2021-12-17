/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kato.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/20 19:17:37 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/04/29 20:56:00 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h_cub_bonus.h"

static void	cats(void)
{
	printf(RED "\n\n                      (`.-,')\n" RESET);
	printf(RED "                    .-'     ;\n" RESET);
	printf(RED "                _.-'   , `,- \t\t\t    |\\__/,|   (`\\\n" RESET);
	printf(RED "          _ _.-'     .'  /._ \t\t\t  _.|o o  |_   ) )\n" RESET);
	printf(RED "        .' `  _.-.  /  ,'._;)\t\t\t-(((---(((--------\n" RESET);
	printf(RED "       (       .  )-| (\n" RESET);
	printf(RED "        )`,_ ,'_,'  \\_;)\n" RESET);
	printf(RED "('_  _,'.'  (___,))\n" RESET);
	printf(RED " `-:;.-'    \n\n" RESET);
}

void	kato(void)
{
	printf(GRAY "\t______                              _   _           \n");
	printf("\t| ___ \\                            | | | |          \n");
	printf("\t| |_/ /____      _____ _ __ ___  __| | | |__  _   _ \n");
	printf("\t|  __/ _ \\ \\ /\\ / / _ \\ '__/ _ \\/ _` | | '_ \\| | | |\n");
	printf("\t| | | (_) \\ V  V /  __/ | |  __/ (_| | | |_) | |_| |\n");
	printf("\t\\_|  \\___/ \\_/\\_/ \\___|_|  \\___|\\__,_| |_.__/ \\__, |\n");
	printf(PURPLE "\t                       __ __ ___  __________   ");
	printf(RESET GRAY "__/ |\n");
	printf(PURPLE "\t                      / //_//   |/_  __/ __ \\ ");
	printf(RESET GRAY "|___/ \n");
	printf(PURPLE "\t                     / ,<  / /| | / / / / / /\n");
	printf("\t                    / /| |/ ___ |/ / / /_/ / \n");
	printf("\t                   /_/ |_/_/  |_/_/  \\____/  \n" RESET);
	cats();
}

/*






      \    /\
       )  ( ')
      (  /  )
jgs    \(__)|

 |\__/,|   (`\
 |_ _  |.--.) )
 ( T   )     /
(((^_(((/(((_/

  



typedef struct	s_cube
{
	char	*name;
	char	*path;
}				t_cube;

void func()
{
	t_cube *yo;

	//yo = malloc(sizeof(t_cube) * 5);
	yo[0] = (t_cube){"nombre", "ruta"};
	yo[1] = (t_cube){"nombre", "ruta"};
	yo[2] = (t_cube){"nombre", "ruta"};
	yo[3] = (t_cube){"nombre", "ruta"};

}*/