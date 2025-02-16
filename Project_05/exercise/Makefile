############################################################
# This make file demonstrated all special variables
# student copy
############################################################

# Standard compile flags
CC       = gcc
CFLAGS   = -O1 -g -Wall -std=c99 -pedantic
CFILES = a.c b.c c.c
OFILES = $(patsubst %.c, %.o, $(CFILES))
MEMTXT = mem.txt


# This demonstrates the returned target name
# $@ to represent the  full target name of the current target
target1 target2:
	@echo "Targets name is " $@

#$? returns the dependencies that are newer than the current target
bin1 : $(CFILES)
	@echo "Dependency change for bin1 is '$?'"
	gcc a.c b.c c.c -o bin1


#$^ returns the names of all the dependencies with space as the delimiter
#$< returns the name of the first dependency
bin2 : $(OFILES)
	@echo "Linking '$^' to '$@'"
	@echo "The first dependency of '$^' is '$<'"
	gcc $^ -o $@

# This checks the associated .c files for the passed .o files
# assumes CC and CFLAGS variable for the passed list of objects
#.c.o :
#	@echo "Compiling '$'"
#	gcc $*.c -c
 
# This checks the associated .c files and o files, similar to
# the .c.o: rule but gives more control
%.o : %.c
	@echo "Dependency change is '$*'"
	gcc $*.c -c

# This rule really does a multi-comparison of all of the object 
# against all the the source file.  It doesn't compile the minimum
# set
#a.o b.o c.o : a.c b.c c.c
#	@echo "Compiling '$*.c'"
#	gcc $*.c -c
#
clean:
	-rm -f *.o bin1 bin2
   

.PHONY: mem
mem: bin2
	valgrind --tool=memcheck --leak-check=yes --error-exitcode=99 --track-origins=yes ./bin2 &> $(MEMTXT)

