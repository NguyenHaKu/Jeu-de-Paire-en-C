paires.out : saeMain.o ChargerMode.o Jeu.o
	gcc -Wall -ansi -o paires.out saeMain.o ChargerMode.o Jeu.o -lgraph -lm

saeMain.o : saeMain.c
	gcc -c saeMain.c

ChargerMode.o : ChargerMode.c ChargerMode.h
	gcc -c ChargerMode.c

Jeu.o : Jeu.c Jeu.h
	gcc -c Jeu.c

clean :
	rm -f *.o

run : paires.out
	./paires.out
