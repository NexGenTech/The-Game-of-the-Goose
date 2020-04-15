#paths
INCLUDE = include
OBJDIR = obj
SRCDIR = src

# compiler
CC = gcc

# Executable names
GAME = goose_game

#flags
CFLAGS = -Wall -g -pedantic -I$(INCLUDE)
VFLAGS = --leak-check=full -v

SRCS    = $(shell find $(SRCDIR) -name '*.c')
OBJS    = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

#Each executable's object files
GAME_OBJS = $(OBJDIR)/space.o $(OBJDIR)/player.o $(OBJDIR)/object.o \
 $(OBJDIR)/game.o $(OBJDIR)/game_reader.o $(OBJDIR)/graphic_engine.o \
 $(OBJDIR)/screen.o $(OBJDIR)/die.o $(OBJDIR)/inventory.o $(OBJDIR)/set.o \
 $(OBJDIR)/command.o $(OBJDIR)/link.o $(OBJDIR)/game_loop.o

PL_TEST_OBJ = player_test.o 


all: tests build $(GAME)

$(GAME): $(GAME_OBJS)


tests: $(TEST_EXEC)
%_test: $(OBJDIR)/%.o
	 $(CC) -o $@ $(CFLAGS) $^

build: $(OBJS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)




clean:
	rm -f $(OBJS)
