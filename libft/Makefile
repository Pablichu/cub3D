NAME		= 	libft.a

CC			= 	@cc
CFLAGS		= 	-I. -Wall -Werror -Wextra -g3
RM			= 	@rm -f

HEADER		=	h_libft.h

SRCS		=	ft_memset.c \
				ft_strrchr.c \
				ft_strlen.c \
				ft_bzero.c \
				ft_strnstr.c \
				ft_memcpy.c \
				ft_strncmp.c \
				ft_memccpy.c \
				ft_atoi.c \
				ft_memmove.c \
				ft_isalpha.c \
				ft_memchr.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strchr.c \
				ft_isprint.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isalnum.c \
				ft_memcmp.c \
				ft_strlcpy.c \
				ft_calloc.c \
				ft_strlcat.c \
				ft_strdup.c \
				ft_strmapi.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_putchar_fd.c \
				ft_putstr_fd.c \
				ft_putendl_fd.c \
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_putchar.c \
				ft_isspace.c \
				get_next_line.c \
				set_bit.c \
				reset_bit.c \
				is_bit_set.c

DIR_L		=	srcs_libft

OBJS_L		=	${addprefix $(DIR_L)/,${SRCS:.c=.o}}

$(NAME):		${HEADER} ${OBJS_L}
				@echo LIBFT COMPILING...
				@ar rcs ${NAME} ${OBJS_L}
				@ranlib $(NAME)
				@make clean
				@echo LIBFT COMPILED!!

all:			${NAME}

clean:			
				${RM}	${OBJS_L}

fclean:			clean	
				${RM}	${NAME}

re:				fclean all

.PHONY:			all clean fclean re
