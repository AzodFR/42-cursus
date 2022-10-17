NAME = librsb.so

OUTPUT = main.out

OBJ =	srcs/addition.s
OBJS = $(OBJ:.s=.o)

INC = includes/

CC = nasm
FLAGS = -f elf64
INCFLAGS = -I$(INC)

RM = rm -f

$(NAME): $(OBJS)
	gcc -shared $(OBJS) -o $(NAME) 

%.o: %.s $(INC)rsb.h
	$(CC) $(FLAGS) $(INCFLAGS) $< -o $(<:.s=.o)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(OUTPUT)

main: $(NAME)
	@gcc -no-pie -Wall -Wextra -Werror $(INCFLAGS) main.c -L. -lrsb -o $(OUTPUT)
	@make clean
	clear
	@./$(OUTPUT)

re: fclean all

.PHONY: all clean fclean re main $(NAME)
