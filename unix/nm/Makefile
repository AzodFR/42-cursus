NAME = nm

LIBFT = libftprintf.a


INCLUDES = includes/

SRC = srcs/

FLAGS = -Wall -Wextra -Werror -g3

CC = gcc $(FLAGS)


FILES = nm.c

RM = rm -f

OBJ = $(addprefix $(SRC), $(FILES))

OBJS = $(OBJ:.c=.o)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) -L. -lftprintf -fsanitize=address -g3 -o $@ -I$(INCLUDES) -Ilibft/${INCLUDES}

$(LIBFT):
	make -C libft/
	@cp libft/$(LIBFT) .

%.o: %.c $(INCLUDES) libft/${INCLUDES}
	gcc -Wall -Wextra -Werror -fsanitize=address -g3 -o $@ -c $< -I$(INCLUDES) -Ilibft/${INCLUDES}

all: $(NAME)

clean:
	make clean -C libft/
	$(RM) $(LIBFT)
	$(RM) $(OBJS)
	@printf "$(LIBFT) [\033[31mX\033[0m]\n"

fclean: clean
	make fclean -C libft/
	$(RM) $(OBJS)
	$(RM) $(NAME)


re: fclean all

.PHONY: all clean fclean re nm libftprintf.a 
