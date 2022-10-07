GCC_FLAG = -Wall -Wextra -Werror
NASM_FLAG = -f elf64
GCC = gcc
NASM = nasm

COLLEEN = Colleen
GRACE = Grace
SULLY = Sully

SRC_COLLEEN = Colleen.s
SRC_GRACE = Grace.s
SRC_SULLY = Sully.s

all: $(COLLEEN) $(GRACE) $(SULLY)

%.o: %.s
	$(NASM) $(NASM_FLAG) $< -o $@

$(COLLEEN): $(SRC_COLLEEN:.s=.o)
	$(GCC) $(GCC_FLAG) -o $@ $<

$(GRACE): $(SRC_GRACE:.s=.o)
	$(GCC) $(GCC_FLAG) -o $@  $<

$(SULLY): $(SRC_SULLY:.s=.o)
	$(GCC) $(GCC_FLAG) -o $@ $< -fsanitize=address -g

clean:
	rm -f $(SRC_COLLEEN:.s=.o) $(SRC_GRACE:.s=.o) $(SRC_SULLY:.s=.o)

fclean: clean
	rm -f $(COLLEEN) $(GRACE) $(SULLY) Sully_*

re: fclean all

.PHONY: all clean fclean re
