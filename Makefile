paires : main.o mode.o jeu.o
	gcc -Wall -ansi -o paires.out main.o mode.o jeu.o -lgraph -lm

main.o : saeMain.c
	gcc -c saeMain.c

mode.o : ChargerMode.c ChargerMode.h
	gcc -c ChargerMode.c

jeu.o : Jeu.c Jeu.h
	gcc -c Jeu.c

clean :
	rm -f *.o

run :
	./paires.out
