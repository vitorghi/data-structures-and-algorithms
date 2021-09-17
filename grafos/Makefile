build:
	gcc -std=c99 -Wall -Werror -c grafo-matrix.c
	gcc -std=c99 -Wall -Werror -c main-matrix-representation.c
	gcc main-matrix-representation.o grafo-matrix.o -lm -o grafo-matrix

run:
	./grafo-matrix

clean:
	rm *.o
	rm grafo-matrix