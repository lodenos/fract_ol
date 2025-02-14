NAME = fractol

CC = clang
CFLAGS = -Wall -Wextra -Werror \
  -Weverything -Wno-poison-system-directories -Wno-padded

SRC_DIR = ./src
OBJ_DIR = ./obj

LIB_LINK = -L /usr/X11/lib -lX11 -lXext

LIB_PATH_C_STANDARD = ./c_standard

INCLUDES = \
  -I ./inc \
  -I $(LIB_PATH_C_STANDARD)/inc \
  -I /usr/X11/include

SRCS = \
  main.c \
  \
  diagram/diagram_delete.c \
  diagram/diagram_fill_image.c \
  diagram/diagram_fn_default_coordinate_delete.c \
  diagram/diagram_fn_default_coordinate_new.c \
  diagram/diagram_fn_default_coordinate_update.c \
  diagram/diagram_fn_default_data_point_delete.c \
  diagram/diagram_fn_default_data_point_new.c \
  diagram/diagram_mouve.c \
  diagram/diagram_new.c \
  diagram/diagram_new_init.c \
  diagram/diagram_run.c \
  diagram/diagram_zoom.c \
  \
  event/event_loop.c \
  \
  fractal/fractal_data_point_new.c \
  fractal/fractal_mandelbrot.c \
  \
  image/image_delete.c \
  image/image_new.c \
  image/image_new_init.c \
  \
  post_processing/data_point_fill_image.c

OBJS = $(patsubst %.c,%.o,$(SRCS))

all: $(NAME)

$(NAME): $(addprefix $(OBJ_DIR)/,$(OBJS))
	$(CC) $(INCLUDES) $(LIB_LINK) $(addprefix $(OBJ_DIR)/,$(OBJS)) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -rf $(NAME)

re: fclean

.PHONY: all clean fclean re
