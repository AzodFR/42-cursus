NAME = push_swap

CHECKER = checker

INCLUDES = includes/

SRC = src/

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

CC = gcc $(FLAGS)

FILES =  \
		utils/lst/list.c utils/lst/list_two.c \
		utils/lst/wrmalloc.c \
		\
		utils/str/ft_strlen.c utils/str/is.c \
		utils/str/split.c utils/str/atol.c \
		utils/str/ft_strcmp.c \
		\
		utils/get_info.c utils/get_info2.c utils/exit.c \
		utils/sorting_ref.c \
		\
		operations/swap.c operations/push.c \
		operations/rotate.c \
		\
		sorting/is_sort.c \
		sorting/little_algo.c  sorting/algo.c\
		\
		parse.c print.c 

PS_FILES = push_swap.c 

CHK_FILES = \
			utils/gnl/get_next_line.c utils/gnl/get_next_line_utils.c \
			\
			checker.c 

CHK_OBJ = $(addprefix $(SRC), $(CHK_FILES))

CHK_OBJS = $(CHK_OBJ:.c=.o)

PS_OBJ = $(addprefix $(SRC), $(PS_FILES))

PS_OBJS = $(PS_OBJ:.c=.o)

OBJ = $(addprefix $(SRC), $(FILES))

OBJS = $(OBJ:.c=.o)

all: $(NAME) $(CHECKER)

$(NAME): $(OBJS) $(PS_OBJS)
	@$(CC) $(OBJS) $(PS_OBJS) -o $@ -I$(INCLUDES)
	@printf "\n\e[36mpush\e[0m_\e[33mswap \e[92mis ready !\e[0m\e[?25h\n"

$(CHECKER) : $(OBJS) $(CHK_OBJS)
	@$(CC) $(OBJS) $(CHK_OBJS) -o $@ -I$(INCLUDES)
	@printf "\n\e[35mchecker \e[92mis ready !\e[0m\e[?25h\n"

%.o: %.c $(INCLUDES)
	@$(CC) -o $@ -c $< -I$(INCLUDES)
	@printf "\e[?25l\e[JCreated \e[92m$(notdir $@)\e[0m\r"

clean:
	@$(RM) $(OBJS) $(PS_OBJS) $(CHK_OBJS)
	@printf "All object files [\033[31mX\033[0m]\n"

fclean: clean
	@$(RM) $(NAME) $(CHECKER)
	@printf "$(NAME) [\033[31mX\033[0m]\n"

slow: fclean
	

re : fclean all