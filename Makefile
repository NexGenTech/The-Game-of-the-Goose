#paths
INCLUDE = include
OBJDIR = obj
SRCDIR = src
DOC = doc

# compiler
CC = gcc

# Executable names
GAME = goose_game
TESTS = player_test die_test set_test link_test inventory_test

#flags
CFLAGS = -Wall -g -pedantic -I$(INCLUDE)
VFLAGS = --leak-check=full -v

#the whole project's object source and object files
SRCS    = $(shell find $(SRCDIR) -name '*.c')
OBJS    = $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

#The goose_game arguments
ARGS = Game_of_Goose.dat

#Each executable's object files
GAME_OBJS = $(OBJDIR)/space.o $(OBJDIR)/player.o $(OBJDIR)/object.o \
 $(OBJDIR)/game.o $(OBJDIR)/game_reader.o $(OBJDIR)/graphic_engine.o \
 $(OBJDIR)/screen.o $(OBJDIR)/die.o $(OBJDIR)/inventory.o $(OBJDIR)/set.o \
 $(OBJDIR)/command.o $(OBJDIR)/link.o $(OBJDIR)/game_loop.o

PL_TEST_OBJ = $(OBJDIR)/player_test.o $(OBJDIR)/player.o $(OBJDIR)/inventory.o $(OBJDIR)/set.o $(OBJDIR)/object.o
DIE_TEST_OBJ = $(OBJDIR)/die_test.o $(OBJDIR)/die.o
SET_TEST_OBJ = $(OBJDIR)/set_test.o $(OBJDIR)/set.o
LINK_TEST_OBJ = $(OBJDIR)/link_test.o $(OBJDIR)/link.o
INV_TEST_OBJ = $(OBJDIR)/inventory_test.o $(OBJDIR)/inventory.o $(OBJDIR)/set.o


all: build tests $(GAME)

tests: $(TESTS)


$(GAME): $(GAME_OBJS)
	$(CC) -o $@ $(GAME_OBJS) $(CFLAGS)

player_test: $(PL_TEST_OBJ)
	$(CC) -o $@ $(PL_TEST_OBJ) $(CFLAGS)

die_test: $(DIE_TEST_OBJ)
	$(CC) -o $@ $(DIE_TEST_OBJ) $(CFLAGS)

set_test: $(SET_TEST_OBJ)
	$(CC) -o $@ $(SET_TEST_OBJ) $(CFLAGS)

link_test: $(LINK_TEST_OBJ)
	$(CC) -o $@ $(LINK_TEST_OBJ) $(CFLAGS)

inventory_test: $(INV_TEST_OBJ)
	$(CC) -o $@ $(INV_TEST_OBJ) $(CFLAGS)

build: $(OBJS)
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) -c $< -o $@ $(CFLAGS)


clean:
	rm -f $(OBJS) $(TESTS) $(GAME)

run: $(GAME)
	./$(GAME) $(ARGS)

valgrind: $(GAME)
	valgrind $(VFLAGS) ./$(GAME) $(ARGS)

doxygen:
	doxygen Doxyfile
