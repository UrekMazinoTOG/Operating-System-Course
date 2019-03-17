CC		= gcc
DEPS	= $(wildcard *.h)
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
PROGRA	= ex1
CFLAGS	= -std=c11 -Wall -O2

# Link object file
$(PROGRA)	: $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@ -s
# Compile main file
ex1.o 		: ex1.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ -c
# Compile .c -> .o
%*.o		: %*.c $(DEPS)
	$(CC) $(CFLAGS) $< -o $@ -c

.PHONY 		: all clean run
all			: $(PROGRA)
clean 		:
	@echo "Cleaning up"
	@rm -f *.o
