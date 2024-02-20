all : main exo3 exo1_test 

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

exo3: biblioH.o entreeSortieH.o biblioC.o entreeSortieLC.o exo3.c
	gcc -Wall -o exo3 exo3.c entreeSortieH.o biblioH.o biblioC.o entreeSortieLC.o

exo1_test : biblioC.o entreeSortieLC.o exo1_test.c 
	gcc -Wall -o exo1_test exo1_test.c biblioC.o entreeSortieLC.o

clean:
	rm -rf *.o
	rm -rf *.gch
	rm -f main









