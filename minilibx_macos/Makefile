NAME = libmlx.a
SRC = mlx_shaders.c mlx_new_window.m mlx_init_loop.m mlx_new_image.m mlx_xpm.c mlx_int_str_to_wordtab.c
OBJ1 = $(SRC:.c=.o)
OBJ = $(OBJ1:.m=.o)
CFLAGS+ = -O3 -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	@ar -r $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@rm -f $(OBJ) *~
	@rm -f mlx_app

fclean: clean
	@rm -f libmlx.a

re: clean all
