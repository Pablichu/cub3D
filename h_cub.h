/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   h_cub.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmira-pe <pmira-pe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/28 19:52:25 by pmira-pe          #+#    #+#             */
/*   Updated: 2021/05/10 19:45:16 by pmira-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_CUB_H
# define H_CUB_H

# include "libft/h_libft.h"
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include "minilibx/mlx.h"

# define RESET			  "\x1b[0m"
# define WHITE			  "\x1b[1m"
# define WHITE_BOX_WHITE    "\x1b[47m"
# define WHITE_BOX_CYAN     "\x1b[46m"
# define WHITE_BOX_PURPLE   "\x1b[45m"
# define WHITE_BOX_BLUE     "\x1b[44m"
# define WHITE_BOX_YELLOW   "\x1b[43m"
# define WHITE_BOX_GREEN    "\x1b[42m"
# define WHITE_BOX_RED      "\x1b[41m"
# define WHITE_BOX_CLEAR    "\x1b[40m"
# define INVISIBLE          "\x1b[8m"
# define WHITE_BOX          "\x1b[7m"
# define WHITE_SUB          "\x1b[4m"
# define WHITE_CURS         "\x1b[3m"
# define GRAY			   "\x1b[2m"
# define BLACK			  "\x1b[30m"
# define RED			    "\x1b[31m"
# define GREEN			  "\x1b[32m"
# define YELLOW			 "\x1b[33m"
# define BLUE			   "\x1b[34m"
# define PURPLE			 "\x1b[35m"
# define CYAN			   "\x1b[36m"
//What can be in Map
# define ALLCHARS	" 012NNSEW"
# define ALLSPRITES	"2"
# define WHILEMAP	"012NSEW"
// Max screen size
# define MAX_X		2560
# define MAX_Y		1395
// Buttons
# define K_ESC  	53
# define K_W    	13
# define K_A    	0
# define K_S    	1
# define K_D    	2
# define K_LEFT 	123
# define K_RIGHT	124

# define SF			64
# define MVSPEED	0.05
# define ROTSPEED	0.025
# define UDIV		1
# define VDIV		1
# define VMOVE		0.0

typedef struct s_bitindex
{
	int	index[8];
}				t_bitindex;

typedef struct s_sprite
{
	double	x;
	double	y;
	int		txt;
	double	dst;
}				t_sprite;

typedef struct s_raycast
{
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
	double	deltaDistX;
	double	deltaDistY;
	double	*ZBuffer;
}				t_raycast;

typedef struct s_txt
{
	int		texX;
	double	texPos;
	double	step;
	int		texNum;
	int		hit;
	int		side;
	int		mapX;
	int		mapY;
	double	rayDirX;
	double	rayDirY;
	double	sideDistX;
	double	sideDistY;
	char	*dst;
}				t_txt;

typedef struct s_spr
{
	int		sprHht;
	int		sprWth;
	int		sprScrnX;
	int		vMvScn;
	int		dwSrtY;
	int		dwSrtX;
	int		dwEndX;
	int		dwEndY;
}				t_spr;

typedef struct s_map
{
	int					args_mode;

	int					r[2];
	char				*txts[5];
	int					f[3];
	int					floor;
	int					c[3];
	int					celen;

	struct s_list		*maplst;
	char				**map;
	float				ply_pos[2];
	int					ply_dir;
	int					ln;
	int					len;
	int					mpln;

	struct s_list		*sprlst;
	int					sprNum;

	int					aux;
	struct s_bitindex	bit;
}				t_map;

typedef struct s_keys
{
	int	move_left;
	int	move_right;
	int	move_back;
	int	move_forward;
	int	look_left;
	int	look_right;
}				t_keys;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_main
{
	struct s_map		flnf;
	struct s_vars		mlx;
	struct s_keys		key;
	struct s_raycast	ray;
	struct s_img		img;
	struct s_img		txt[5];
	struct s_txt		inf;
	struct s_spr		spr;
}				t_main;

//FILE READING
void			map_parse(t_map *flnf);
void			moving_ply(t_main *main);
void			check_line_bend(char *ln);
int				reading(int fd, char **buff);
void			clear_map_line(void *content);
void			basic_resolution(t_map *flnf);
void			basic_check(t_map *flnf, int i);
void			file_reader(int fd, t_map *flnf);
int				file_conf(char *buff, t_map *flnf);
int				get_rgb(char *buff, int *c, int i, int j);
void			taking_map(int fd, char *buff, t_map *flnf);
void			new_sprite_pos(t_map *flnf, int i, int txt);
int				going_to_conf(char *buff, t_map *flnf, int mode);
int				resolution(char *buff, t_map *flnf, int i, int j);
int				path_to_textures(char *buff, t_map *flnf, int mode);
char			*until_map_nothing(int fd, char *buff, t_map *flnf);
//RAYCASTING
int				raycast(t_main *main);
int				game_close(t_main *main);
void			hooks_or_bmp(t_main *main);
void			texture_select(t_main *main);
void			sprites_going_in(t_main *main);
int				calculating_stepX(t_main *main);
int				calculating_stepY(t_main *main);
int				hi_key(int keycode, t_main *main);
int				bye_key(int keycode, t_keys *key);
void			init_variables(t_main *main, int x);
void			please_not_much_resolution(t_main *main);
unsigned int	my_mlx_get_pixel(t_img *data, int x, int y);
void			distance_from_player(t_main *main, void *content);
void			checking_wall_hit(t_main *main, int stepX, int stepY);
void			my_mlx_pixel_put(t_img *data, int x, int y, int color);
void			calculating_sides(t_main *main, double *perpWallDist, int x);
void			lstiter_adapted(t_main *main, t_list *lst,
					void (*f)(t_main *, void *));
void			checking_hit(t_main *main, double perpWallDist,
					int *drawEnd, int *drawStart);
//CREATE BMP
void			create_bmp(t_main *main);
//ERRORS FUNTIONS
void			no_map(int i);
void			file_error(int type, int ln, int fd);
void			raycast_error(int type, t_main *main, int i);
void			map_parse_error(t_map *flnf, int i, int j, int parse);
#endif
