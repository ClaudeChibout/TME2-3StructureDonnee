all : main autre

biblioC.o: biblioC.c biblioC.h
	gcc -c biblioC.c biblioC.h

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
	gcc -c  entreeSortieLC.c entreeSortieLC.h

biblioH.o: biblioH.c
	gcc -Wall -c -o biblioH.o biblioH.c

entreeSortieH.o: entreeSortieH.c
	gcc -Wall -c -o entreeSortieH.o entreeSortieH.c

main: biblioH.o entreeSortieH.o biblioC.o entreeSortieLC.o main.c
	gcc -Wall -o main main.c entreeSortieH.o biblioH.o biblioC.o entreeSortieLC.o

autre: biblioH.o entreeSortieH.o biblioC.o entreeSortieLC.o autre.c
	gcc -Wall -o autre autre.c entreeSortieH.o biblioH.o biblioC.o entreeSortieLC.o

clean:
	rm -rf *.o
	rm -rf *.gch
	rm -f main









