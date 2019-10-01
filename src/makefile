# The compiler
CC=gcc
# -Wall turns on most, but not all, compiler
# -g adds debugging information to the executable file
CFLAGS=-Wall -g

# Define any directories containing headers files
INCLUDE=-I../include

# Define any directories containing any libraries
LFLAGS=-L../lib

# Define the C source files
SRCS = main.c $(wildcard ../lib/*c)

# Define the C Object files
# This uses Suffix Replacement within a macro:
#   $(name:string1=string2)
#         For each word in 'name' replace 'string1' with 'string2'
# Below we are replacing the suffix .c of all words in the macro SRCS
# with the .o suffix
OBJS=$(SRCS:.c=.o)

MAIN=main

all: $(MAIN) $(SRCS)

# this is a suffix replacement rule for building .o's from .c's
# it uses automatic variables $<: the name of the prerequisite of
# the rule(a .c file) and $@: the name of the target of the rule (a .o file) 
# (see the gnu make manual section about automatic variables)
.c.o: 
	$(CC) $(CFLAGS) $(INCLUDE) -c $<  -o $@
	
$(MAIN): $(OBJS)
	$(CC) $(CFLAGS) -o $(MAIN) $(OBJS) $(LFLAGS) $(INCLUDE)

.PHONY: depend clean

clean:
	del *.o *~ $(MAIN) *.exe 

depend: $(SRCS)
	makedepend $(INCLUDES) $^
