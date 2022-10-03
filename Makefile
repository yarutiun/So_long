NAME = so_long
SRC = src/main.c \
	  src/map_validator.c \
	  src/utils.c \
	  src/map_check_correct.c \
      src/get_next_line.c \
	  src/get_next_line_utils.c \
	  src/render_game.c \
	  src/key_handling.c \

# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit  -o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME):
	@$(MAKE) -C mlx/
	@$(CC) $(SRC) $(FLAGS) $(NAME)
	@echo "Everything compiled successfully"

clean:
	@$(RM) so_long
	
fclean: clean
	@$(MAKE) clean -C mlx/
	
re: fclean all
# -Og -g3 -fsanitize=address