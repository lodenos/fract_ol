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

LIBFT_PATH = ./libft
MINILIBX_PATH = ./minilibx-linux

INCLUDES = \
  -I $(MINILIBX_PATH) -L $(MINILIBX_PATH) -lmlx \
  -I /usr/X11/include -L /usr/X11/lib -lX11 -lXext \
  -I $(LIBFT_PATH)/inc -L $(LIBFT_PATH) -lft \
  -I ./inc

LIBFT = $(LIBFT_PATH)/libft.a
MINILIBX = $(MINILIBX_PATH)/libmlx.a

all: $(NAME)

$(LIBFT):
	make -C $(LIBFT_PATH)

$(MINILIBX):
	# git clone git@github.com:42Paris/minilibx-linux.git
	make -C $(MINILIBX_PATH) 

$(NAME): $(MINILIBX) $(LIBFT) $(addprefix $(OBJ_DIR)/,$(OBJS))
	$(CC) $(INCLUDES) $(addprefix $(OBJ_DIR)/,$(OBJS)) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	make clean -C $(LIBFT_PATH)
	rm -rf $(OBJ_DIR)

fclean: clean
	make clean -C $(MINILIBX_PATH)
	make fclean -C $(LIBFT_PATH)
	rm -f $(NAME)

re: fclean
	make re -C $(MINILIBX_PATH)
	make re -C $(LIBFT_PATH)

.PHONY: all clean fclean re
