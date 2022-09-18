NAME = so_long
SRC = src/*.c \
      get_next_line/*
INC = inc
CC = clang
LIBPRINT = libftprintf

# -I[/path/to/header-files]
# Add search path to header files (.h) or (.hpp).
FLAGS = -Wall -Wextra -Werror -Iincludes -g -Lmlx -lmlx -framework OpenGL -framework AppKit -I mlx -I $(INC) -I /usr/X11/include -I $(LIBPRINT) -I

all: $(NAME)

%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

$(NAME): 
	$(MAKE) -C mlx/
	$(MAKE) -C libftprintf/
	$(CC) $(SRC) libftprintf/libftprintf.a $(FLAGS) $(NAME)

clean:
	$(RM) $(NAME)
	
fclean: clean
	$(MAKE) clean -C mlx/

re: fclean all
#-Og -g3 -fsanitize=address for debugging