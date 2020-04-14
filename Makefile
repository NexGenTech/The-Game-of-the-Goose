#paths
INCLUDE = include
SOURCE = src
OBJS = obj

# compiler
CC = gcc

#flags
CFLAGS = -Wall -g -pedantic -I$(INCLUDE)
VFLAGS = --leak-check=full -v

$(OBJS)/%.o: $(SOURCE)/%.c $(INCLUDE)/%.h
	$(CC) -c $< $(CFLAGS) -o $@

OB = $(OBJS)/space.o $(OBJS)/command.o $(OBJS)/screen.o $(OBJS)/graphic_engine.o $(OBJS)/game.o $(OBJS)/object.o $(OBJS)/player.o $(OBJS)/game_reader.o $(OBJS)/die.o $(OBJS)/set.o $(OBJS)/inventory.o $(OBJS)/link.o $(OBJS)/game_loop.o

TESTS = die_test set_test player_test link_test inventory_test

all: goose_game tests

tests: $(TESTS)

goose_game: $(OB)
	$(CC) -o $@ $(OB) $(CFLAGS)

die_test: die_test.o
	$(CC) -o $@ die.c die_test.o $(CFLAGS)
set_test: set_test.o
	$(CC) -o $@ set.c set_test.o $(CFLAGS)
player_test: player_test.o
	$(CC) -o $@ player_test.o player.c object.c inventory.c set.c $(CFLAGS)
link_test: link_test.o
	$(CC) -o $@ link_test.o link.c $(CFLAGS)
inventory_test: inventory_test.o
	$(CC) -o $@ inventory_test.o inventory.c set.c $(CFLAGS)

clean:
	rm -rf $(OBJS)/%.o  tests LOG

valgrind:
