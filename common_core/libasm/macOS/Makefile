NAME = libasm.a

OUTPUT = main.out

OBJ =	srcs/ft_strlen.s \
		srcs/ft_strcpy.s \
		srcs/ft_strcmp.s \
		srcs/ft_strdup.s \
		srcs/ft_read.s \
		srcs/ft_write.s
OBJS = $(OBJ:.s=.o)

INC = includes/

CC = nasm
FLAGS = -f macho64
INCFLAGS = -I$(INC)

RM = rm -f

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.s $(INC)libasm.h
	$(CC) $(FLAGS) $(INCFLAGS) $< -o $(<:.s=.o)

all: $(NAME)

clean:
	$(RM) $(OBJS) ft_write.txt write.txt

fclean: clean
	$(RM) $(NAME) $(OUTPUT)

main: $(NAME)
	@gcc -Wall -Wextra -Werror $(INCFLAGS) main.c -L. -lasm -o $(OUTPUT)
	@make clean
	clear
	@./$(OUTPUT)

re: fclean all

.PHONY: all clean fclean re main $(NAME)
