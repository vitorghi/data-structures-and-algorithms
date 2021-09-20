build:
	gcc -std=c99 -Wall -Werror -c ../representation/grafo-lista.c
	gcc -std=c99 -Wall -Werror -c topological-sort.c
	gcc -g -fsanitize=address topological-sort.o grafo-lista.o -lm -o topological-sort

run:
	./topological-sort < input

clean:
	rm *.o
	rm topological-sort