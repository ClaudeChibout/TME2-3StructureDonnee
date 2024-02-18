all : main

biblioC.o: biblioC.c biblioC.h
	gcc -c biblioC.c biblioC.h

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
	gcc -c  entreeSortieLC.c entreeSortieLC.h

main.o: main.c 
	gcc -c  main.c

main:  main.o biblioC.o entreeSortieLC.o
	gcc -o main -Wall main.o biblioC.o entreeSortieLC.o


clean:
	rm -rf *.o
	rm -rf *.gch









