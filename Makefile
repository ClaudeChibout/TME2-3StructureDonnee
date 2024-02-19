all : mainH mainlc

biblioC.o: biblioC.c biblioC.h
	gcc -c biblioC.c biblioC.h

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
	gcc -c  entreeSortieLC.c entreeSortieLC.h

main.o: main.c 
	gcc -c  main.c

biblioH.o: biblioH.c
	gcc -Wall -c -o biblioH.o biblioH.c

entreeSortieH.o: entreeSortieH.c
	gcc -Wall -c -o entreeSortieH.o entreeSortieH.c

mainH: biblioH.o entreeSortieH.o ex2.c 
	gcc -Wall -o mainH ex2.c entreeSortieH.o biblioH.o

mainlc:  main.o biblioC.o entreeSortieLC.o
	gcc -o mainlc -Wall main.o biblioC.o entreeSortieLC.o

clean:
	rm -rf *.o
	rm -rf *.gch









