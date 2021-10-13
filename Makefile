NAME	= so_long

B_NAME	= so_long_bonus

SRCS	= main.c map_starter.c map_checker.c helpers.c keys.c

B_SRCS	= bonus/main_bonus.c bonus/map_starter_bonus.c bonus/map_checker_bonus.c bonus/helpers_bonus.c bonus/keys_bonus.c bonus/animation_bonus.c bonus/digits_bonus.c

OBJS	= ${SRCS:.c=.o}

B_OBJS	= ${B_SRCS:.c=.o}

CFLAGS	= -Wall -Wextra -Werror

MLX_DIR = minilibx_opengl_20191021

%.o: %.c solong.h ./bonus/solong_bonus.h
	gcc -c ${CFLAGS} -I . $< -o ${<:.c=.o}

${NAME}: ${OBJS} solong.h
	ar rc libsolong.a ${OBJS}
	ranlib libsolong.a
	make -C ${MLX_DIR}
	cd ..
	gcc ${CFLAGS} ${MLX_DIR}/libmlx.a -lmlx -framework OpenGL -framework AppKit ${OBJS} -L. -lsolong -o ${NAME}

all:	${NAME}

${B_NAME}: ${B_OBJS} bonus/solong_bonus.h
	ar rc libsolong.a ${B_OBJS}
	ranlib libsolong.a
	make -C ${MLX_DIR}
	cd ..
	gcc ${CFLAGS} ${MLX_DIR}/libmlx.a -lmlx -framework OpenGL -framework AppKit ${B_OBJS} -L. -lsolong -o ${B_NAME}

bonus:	${B_NAME}

clean:
	rm -f ${OBJS} ${B_OBJS}
	make -C ${MLX_DIR} clean
	cd ..

fclean:	clean
	rm -f ${NAME} ${B_NAME} libsolong.a

re: fclean all

.PHONY:	all fclean clean re bonus








