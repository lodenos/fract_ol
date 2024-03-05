NAME = fractol

CC = clang
CFLAGS = #-Wall -Wextra -Werror

SRC_DIR = ./src
OBJ_DIR = ./obj

SRCS = \
  main.c \
  \
  event/event.c \
  event/event_keyboard_press.c \
  event/event_keyboard_release.c \
  event/event_mouse_click_press.c \
  event/event_mouse_click_release.c \
  event/event_mouse_mouve.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

INCLUDES = \
  -I ./minilibX -L ./minilibX -lmlx \
  -I /usr/X11/include -L /usr/X11/lib -lX11 -lXext \
  -I ./libft/inc -L ./libft -lft \
  -I ./inc

LIBFT = ./libft/libft.a
MINILIBX = ./minilibX/libmlx.a

all: $(NAME)

$(LIBFT):
	make -C ./libft

$(MINILIBX):
	# git clone git@github.com:42Paris/minilibx-linux.git minilibX
	make -C ./minilibX

$(NAME): $(MINILIBX) $(LIBFT) $(addprefix $(OBJ_DIR)/,$(OBJS))
	$(CC) $(INCLUDES) $(addprefix $(OBJ_DIR)/,$(OBJS)) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C ./libft
	rm -rf $(OBJ_DIR)

fclean: clean
	make clean -C ./minilibX
	make fclean -C ./libft
	rm -f $(NAME)

re: fclean
	make re -C ./minilibX
	make re -C ./libft

.PHONY: all clean fclean re
