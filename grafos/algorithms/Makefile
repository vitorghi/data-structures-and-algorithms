build:
	gcc -std=c99 -Wall -Werror -c -g ../representation/grafo-lista.c
	gcc -std=c99 -Wall -Werror -c -g topological-sort.c
	gcc -g topological-sort.o grafo-lista.o -lm -o topological-sort

run:
	./topological-sort < input

clean:
	rm *.o
	rm topological-sort