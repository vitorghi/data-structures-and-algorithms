build:
	gcc -std=c99 -Wall -Werror -c -g ../representation/grafo-lista.c
	gcc -std=c99 -Wall -Werror -c -g depth-first-search.c
	gcc -g depth-first-search.o grafo-lista.o -lm -o depth-first-search

run:
	./depth-first-search < input

clean:
	rm *.o
	rm depth-first-search