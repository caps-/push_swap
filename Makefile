#program name
NAME		= push_swap

#compiler stuff
CC 			= gcc
CFLAGS		= -Wall -Werror -Wextra
INCS		= -Iinclude
RM			= rm -rf

#paths
SRC_PATH	= src/
OBJ_PATH	= obj/

#source files
SRC			= push_swap.c \
			  cost.c \
			  init.c \
			  input_checks.c \
			  input_utils.c \
			  likkle_sort.c \
			  move_em.c \
			  position.c \
			  push.c \
			  reverse_rotate.c \
			  rotate.c \
			  sort_em.c \
			  stack_stuff.c \
			  swap.c \
			  utils.c

SRCS		= $(addprefix $(SRC_PATH), $(SRC))

#object files
OBJ 		= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))


#let's gooooo
all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(MAKE) -C ./ft_printf
	$(CC) $(CFLAGS) $(OBJS) ./ft_printf/libftprintf.a -o $(NAME)

clean:
	$(MAKE) -C ./ft_printf fclean
	$(RM) $(OBJ_PATH)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
