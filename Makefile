#paths
INCLUDE = include
OBJDIR = obj
SRCDIR = src

# compiler
CC = gcc

# Project name
PROJECT = goose_game

#flags
CFLAGS = -Wall -g -pedantic -I$(INCLUDE)
VFLAGS = --leak-check=full -v

SRCS    = $(shell find $(SRCDIR) -name '*.c')
OBJS    = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
TESTS   = $(shell find $(OBJDIR) -name '*_test.o')
TEST_EXEC = $(patsubst $(OBJDIR)/%_test.o, %_test, $(TESTS))

all: build tests

build: $(OBJS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)

tests: $(TEST_EXEC)
%_test: $(OBJDIR)/%.o
	 $(CC) -o $@ $(CFLAGS) $<



clean:
	rm -f $(OBJS)
