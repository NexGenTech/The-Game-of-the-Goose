#paths
INCLUDE = include
SOURCE = src
OBJS = obj

# compiler
CC = gcc

#flags
CFLAGS = -Wall -g -pedantic -I$(INCLUDE)
VFLAGS = --leak-check=full -v

OB = $(OBJS)/space.o $(OBJS)/command.o $(OBJS)/screen.o $(OBJS)/graphic_engine.o $(OBJS)/game.o $(OBJS)/object.o $(OBJS)/player.o $(OBJS)/game_reader.o $(OBJS)/die.o $(OBJS)/set.o $(OBJS)/inventory.o $(OBJS)/link.o $(OBJS)/game_loop.o

build: $(OB)

$(OBJS)/%.o: $(SOURCE)/%.c $(INCLUDE)/%.h
	$(CC) -c $< $(CFLAGS) -o $@
