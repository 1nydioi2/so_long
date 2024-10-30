EXEC_NAME = so_long

SOURCES = main.c \
	floodfill.c\
	game_utils.c\
	gnl.c\
	hooker.c\
	map_checker.c\
	mlx_handler.c\
	mlx_rendering.c\
	utils.c

OBJECTS = $(SOURCES:.c=.o)

COMPILER = cc

COMPILATION_FLAGS = -Wall -Wextra -Werror 

MLX_COMPILATION_FLAGS = -lmlx -lXext -lX11

all: $(EXEC_NAME)

$(EXEC_NAME): $(OBJECTS)
	$(COMPILER) $(COMPILATION_FLAGS) $(MLX_COMPILATION_FLAGS) -o $(EXEC_NAME) $(OBJECTS)

%.o: %.c
	$(COMPILER) $(COMPILATION_FLAGS) $(MLX_COMPILATION_FLAGS) -o $@ -c $<

fclean: clean
	rm -f $(EXEC_NAME) 

clean:
	rm -f $(OBJECTS)

re: fclean all

.PHONY: fclean all clean re
