all: goose_game die_test set_test

goose_game: space.o command.o screen.o graphic_engine.o game_loop.o game.o object.o player.o game_reader.o die.o set.o
	gcc -o goose_game space.o command.o screen.o graphic_engine.o game_loop.o game.o object.o player.o game_reader.o die.o set.o -Wall -g -pedantic
die_test: die_test.o
	gcc -o die_test die.c die_test.o -Wall -pedantic
set_test: set_test.o
	gcc -o set_test set.c set_test.o -Wall -pedantic

space.o: space.c types.h space.h set.h object.h
	gcc -c space.c -Wall -pedantic
command.o: command.c command.h
	gcc -c command.c -Wall -pedantic
screen.o: screen.c screen.h
	gcc -c screen.c -Wall -pedantic
graphic_engine.o: graphic_engine.c graphic_engine.h game.h command.h space.h types.h set.h object.h player.h die.h screen.h
	gcc -c graphic_engine.c -Wall -pedantic
game_loop.o: game_loop.c graphic_engine.h game.h command.h space.h types.h set.h object.h player.h die.h screen.h
	gcc -c game_loop.c -Wall -pedantic
game.o: game.c game_reader.h game.h command.h space.h types.h set.h object.h player.h die.h
	gcc -c game.c -Wall -pedantic
object.o: object.c object.h types.h
	gcc -c object.c -Wall -pedantic
player.o: player.c player.h types.h
	gcc -c player.c -Wall -pedantic
game_reader.o: game_reader.c game_reader.h game.h command.h space.h types.h set.h object.h player.h die.h
	gcc -c game_reader.c -Wall -pedantic
die.o: die.c die.h types.h
	gcc -c die.c -Wall -pedantic
set.o: set.c set.h object.h types.h
	gcc -c set.c -Wall -pedantic
die_test.o: die_test.c die.h types.h
	gcc -c die_test.c -Wall -pedantic
set_test.o: set_test.c set.h object.h types.h
	gcc -c set_test.c -Wall -pedantic

clean:
	rm -rf goose_game space.o command.o screen.o graphic_engine.o game_loop.o game.o object.o player.o game_reader.o die.o set.o die_test.o die_test set_test.o set_test LOG
