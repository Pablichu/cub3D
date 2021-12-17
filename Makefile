NAME	=		cub3D

CC		=		gcc
CFLAGS	=		-I. -O3 -Imlx -Wall -Wextra -Werror# -g3 -fsanitize=address
RM		=		@rm -f

DIR_L			=	libft/
DIR_M			=	minilibx/
HEADER			=	h_cub.h/
H_BONUS			=	h_cub_bonus.h/
DIR_SRCS		=	srcs/
DIR_BONUS_SRCS	=	srcs_bonus/

DAY		=		$(shell date +'%d/%m/%Y %H:%M')

SRCS	=		cub3D.c \
				file_reading/file_reader.c \
				file_reading/map_parse.c \
				file_reading/read_conf.c \
				file_reading/read_conf_aux.c \
				file_reading/read_map.c \
				file_reading/file_aux.c \
				errors_display/file_error.c \
				errors_display/raycast_error.c \
				display_game/raycaster.c \
				display_game/casting_world.c \
				display_game/raycast_compute.c \
				display_game/raycast_aux.c \
				display_game/hook_events.c \
				display_game/sprites_put.c \
				display_game/sprite_sorter.c \
				display_game/mlx_tools.c \
				display_game/moving_steve.c \
				create_bmp/bmp_begins.c

BONUS	=		cub3D.c \
				file_reading/file_reader.c \
				file_reading/map_parse.c \
				file_reading/read_conf.c \
				file_reading/read_conf_aux.c \
				file_reading/read_map.c \
				file_reading/file_aux.c \
				errors_display/file_error.c \
				errors_display/raycast_error.c \
				display_game/raycaster.c \
				display_game/casting_world.c \
				display_game/raycast_compute.c \
				display_game/raycast_aux.c \
				display_game/hook_events.c \
				display_game/sprites_put.c \
				display_game/sprite_sorter.c \
				display_game/mlx_tools.c \
				display_game/moving_steve.c \
				display_game/raycaster_floor.c \
				display_game/ship_move.c \
				display_game/init_param.c \
				display_game/menu.c \
				display_game/sprite_hit.c \
				create_bmp/bmp_begins.c \
				easter_egg/kato.c

OBJS	=		${addprefix $(DIR_SRCS)/,${SRCS:.c=.o}}
OBJS_B	=		${addprefix $(DIR_BONUS_SRCS)/,${BONUS:.c=.o}}

$(NAME):		${HEADER} ${OBJS} 
				@echo "\033[0;36mCompiling..\033[1;34m"
				make -C $(DIR_L)
				@make -C $(DIR_M)
				${CC}  ${OBJS} -o $(NAME) -L. $(DIR_L)/libft.a $(DIR_M)/libmlx.a -framework OpenGL -framework AppKit
				@#-g -fsanitize=address libmlx.dylib
				@echo "\033[1;32mDONE MANIN\033[0m"

bonus:			${H_BONUS} ${OBJS_B}
				@echo "\033[0;36mCompiling bonus..\033[1;34m"
				make -C $(DIR_L)
				@make -C $(DIR_M)
				${CC}  ${OBJS_B} -o $(NAME) -L. $(DIR_L)/libft.a $(DIR_M)/libmlx.a -framework OpenGL -framework AppKit
				@# -fsanitize=address libmlx.dylib
				@echo "\033[1;32mDONE MANIN\033[0m"

all:			${NAME}

clean:
				@${RM} ${OBJS} ${OBJS_B}

fclean:			clean
				@${RM} ${NAME}
				@make -C $(DIR_L) fclean
				@make -C $(DIR_M) clean

re:				
				@make fclean
				@make -C $(DIR_L) fclean
				@make all

git:
				git add .
				git commit -m "$(DAY)"
				git push -u origin master

.PHONY:			all clean fclean re bonus git
