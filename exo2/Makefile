all: main

biblioH.o: biblioH.c
	gcc -Wall -c -o biblioH.o biblioH.c

entreeSortieH.o: entreeSortieH.c
	gcc -Wall -c -o entreeSortieH.o entreeSortieH.c

main: biblioH.o entreeSortieH.o ex2.c
	gcc -Wall -o main ex2.c entreeSortieH.o biblioH.o

clean:
	rm -f *.o