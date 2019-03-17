CC		= gcc
HDRS	= $(wildcard *.h)
SRCS	= $(wildcard *.c)
OBJS	= $(SRCS:.c=.o)
NAME	= myfactorial
OPTS	= -std=c11 -Wall -O2

# Link object file
$(NAME)	: $(OBJS)
	$(CC) $(OPTS) $^ -o $@
# Compile main program
main.o  : main.c $(HDRS)
# Compile .c -> .o
%*.o	: %*.c $(HDRS)
	$(CC) $(OPTS) $< -o $@ -c

.PHONY 		: all clean run

all		: $(NAME)
clean 		:
	@echo "Cleaning up"
	@rm -f *.o
run		: $(NAME)
	./$(NAME)
