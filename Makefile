NAME = so_long
SRC = src/main.c \
	  src/errors.c \
	  src/map_validator.c \
	  src/utils.c \
	  src/map_check_correct.c \
      src/get_next_line.c \
	  src/get_next_line_utils.c \

# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -o

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): 
	$(MAKE) -C mlx/
	$(CC) $(SRC) $(FLAGS) $(NAME)

clean:
	$(RM) so_long
	
fclean: clean
	$(MAKE) clean -C mlx/
	
re: fclean all