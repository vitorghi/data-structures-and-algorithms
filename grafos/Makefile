build:
	gcc -std=c99 -Wall -Werror -c grafo.c
	gcc -std=c99 -Wall -Werror -c main-matrix-representation.c
	gcc main-matrix-representation.o grafo.o -lm -o grafo-matrix

run:
	./grafo-matrix

clean:
	rm *.o
	rm grafo-matrix