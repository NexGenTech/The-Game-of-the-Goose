FLAGS = -Wall -g -pedantic

all: goose_game die_test set_test

tests: die_test set_test player_test link_test inventory_test

goose_game: space.o command.o screen.o graphic_engine.o game_loop.o game.o object.o player.o game_reader.o die.o set.o inventory.o link.o
	gcc -o goose_game space.o command.o screen.o graphic_engine.o game_loop.o game.o object.o player.o game_reader.o die.o set.o inventory.o link.o $(FLAGS)

die_test: die_test.o
	gcc -o die_test die.c die_test.o $(FLAGS)
set_test: set_test.o
	gcc -o set_test set.c set_test.o $(FLAGS)
player_test: player_test.o
	gcc -o player_test player_test.o player.c object.c inventory.c set.c $(FLAGS)
link_test: link_test.o
	gcc -o link_test link_test.o link.c $(FLAGS)
inventory_test: inventory_test.o
	gcc -o inventory_test inventory_test.o inventory.c set.c $(FLAGS)

space.o: space.c types.h space.h set.h object.h
	gcc -c space.c $(FLAGS)
command.o: command.c command.h
	gcc -c command.c $(FLAGS)
screen.o: screen.c screen.h
	gcc -c screen.c $(FLAGS)
graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h set.h object.h player.h die.h screen.h inventory.h link.h
	gcc -c graphic_engine.c $(FLAGS)
game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h set.h object.h player.h die.h screen.h inventory.h link.h
	gcc -c game_loop.c $(FLAGS)
game.o: game.c game_reader.h game.h command.h space.h types.h set.h object.h player.h die.h inventory.h link.h
	gcc -c game.c $(FLAGS)
object.o: object.c object.h types.h
	gcc -c object.c $(FLAGS)
player.o: player.c player.h types.h inventory.h set.h object.h
	gcc -c player.c $(FLAGS)
game_reader.o: game_reader.c game_reader.h game.h command.h space.h types.h set.h object.h player.h die.h
	gcc -c game_reader.c $(FLAGS)
die.o: die.c die.h types.h
	gcc -c die.c $(FLAGS)
set.o: set.c set.h object.h types.h
	gcc -c set.c $(FLAGS)
inventory.o: inventory.c inventory.h set.h object.h types.h
	gcc -c inventory.c $(FLAGS)
link.o: link.c link.h types.h
	gcc -c link.c $(FLAGS)
die_test.o: die_test.c die.h types.h
	gcc -c die_test.c $(FLAGS)
set_test.o: set_test.c set.h object.h types.h
	gcc -c set_test.c $(FLAGS)
inventory_test.o: inventory_test.c inventory.h set.h object.h types.h
	gcc -c inventory_test.c $(FLAGS)
player_test.o: player_test.c player.h types.h inventory.h set.h object.h
	gcc -c player_test.c $(FLAGS)
link_test.o: link_test.c link.h types.h
	gcc -c link_test.c $(FLAGS)

clean:
	rm -rf goose_game space.o command.o screen.o graphic_engine.o game_loop.o game.o object.o player.o game_reader.o die.o set.o die_test.o die_test set_test.o set_test player_test player_test.o inventory_test inventory_test.o inventory.o link_test link_test.o link.o LOG
