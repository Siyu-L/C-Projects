connectn.out: input_validation.o main.o play_game.o set_up_game.o
	gcc -g -Wall -Werror -o connectn.out input_validation.o main.o play_game.o set_up_game.o

main.o: main.c set_up_game.h play_game.h
	gcc -g -Wall -Werror -c main.c

input_validation.o: input_validation.c input_validation.h
	gcc -g -Wall -Werror -c input_validation.c

play_game.o: play_game.c play_game.h input_validation.h
	gcc -g -Wall -Werror -c play_game.c

set_up_game.o: set_up_game.c set_up_game.h
	gcc -g -Wall -Werror -c set_up_game.c	
	
clean:
	rm -fr *.o *.out
