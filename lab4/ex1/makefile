CC	 = gcc
PROG = ex1
OPTS = -std=c11 -Wall -O2
LIBS = -lm

# Link object file
$(PROG)	: main.o ex1.o
	$(CC) $(OPTS) $^ -o $@ -s
# Compile main file
main.o 	: main.c ex1.h
	$(CC) $(OPTS) $(LIBS) $< -o $@ -c
# Compile .c -> .o
ex1.o	: ex1.c ex1.h
	$(CC) $(OPTS) $(LIBS) $< -o $@ -c

.PHONY 	: all clean run
all		: $(PROG)
clean 	:
	@echo "Cleaning up"
	@rm -f *.o $(PROG)
