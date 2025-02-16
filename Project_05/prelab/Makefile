CC = gcc
CFLAGS = -O1 -g -Wall -std=c99 -pedantic

SRCS = $(wildcard *.c)
TARGETS = $(SRCS:.c=)

.PHONY: all
all: $(TARGETS)

%: %.c
	@$(CC) $(CFLAGS) $< -o $@
	@echo "Compiling" $< "! :)"
.PHONY: clean
clean:
	rm -f $(TARGETS)

.PHONY: mem
mem: $(TARGETS)
	for target in $(TARGETS); do \
		valgrind --tool=memcheck --leak-check=yes --error-exitcode=99 --track-origins=yes ./$$target; \
	done

.PHONY: help
help:
	@echo "Options are:"
	@echo "  all    - Build all executables"
	@echo "  clean  - Remove all executables"
	@echo "  mem    - Run valgrind on all executables"
	@echo "  help   - Display this help message"