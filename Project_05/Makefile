CC = gcc
CFLAGS = -O1 -g -Wall -std=c99 -pedantic
TARGETS = TestSearch
SEARCHWORD = space
SOURCES = TestSearch.c LinkedLists.c DynamicArrays.c
WORDLIST = engWords.txt
OUTPUTFILE = out.txt
VALGRINDOUTPUTFILE = mem.txt

.PHONY: all
all: $(TARGETS)

$(TARGETS): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGETS)
	@echo "Compiling" $< "! :)"


.PHONY: clean
clean:
	rm -f $(TARGETS)

.PHONY: test
test: $(TARGETS)
	./$(TARGETS) $(WORDLIST) $(SEARCHWORD) > $(OUTPUTFILE)
	./$(TARGETS) $(WORDLIST) xyzzy >> $(OUTPUTFILE)
	cat $(OUTPUTFILE)

.PHONY: mem
mem: $(TARGETS)
	valgrind --tool=memcheck --leak-check=yes --error-exitcode=99 --track-origins=yes ./$(TARGETS) $(WORDLIST) $(SEARCHWORD) &> $(VALGRINDOUTPUTFILE)
	cat $(VALGRINDOUTPUTFILE)

.PHONY: help
help:
	@echo "Options are:"
	@echo "  all    - Build all executables"
	@echo "  clean  - Remove all executables"
	@echo "  mem    - Run valgrind on all executables"
	@echo "  test   - Run tests using TestSearch.c"
	@echo "  help   - Display this help message"