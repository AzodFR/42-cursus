GCC_FLAG = -Wall -Wextra -Werror
NASM_FLAG = -f elf64
GCC = gcc
NASM = nasm

COLLEEN = Colleen
GRACE = Grace
SULLY = Sully

SRC_COLLEEN = Colleen.c
SRC_GRACE = Grace.c
SRC_SULLY = Sully.c

all: $(COLLEEN) $(GRACE) $(SULLY)

%.o: %.c
	$(GCC) $(GCC_FLAG) -c $< -o $@

$(COLLEEN): $(SRC_COLLEEN:.c=.o)
	$(GCC) $(GCC_FLAG) -o $@ $<

$(GRACE): $(SRC_GRACE:.c=.o)
	$(GCC) $(GCC_FLAG) -o $@ $<

$(SULLY): $(SRC_SULLY:.c=.o)
	$(GCC) $(GCC_FLAG) -o $@ $<

clean:
	rm -f $(SRC_COLLEEN:.c=.o) $(SRC_GRACE:.c=.o) $(SRC_SULLY:.c=.o)

fclean: clean
	rm -f $(COLLEEN) $(GRACE) $(SULLY) Sully_*

re: fclean all

.PHONY: all clean fclean re
