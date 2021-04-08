build:
	gcc -std=c99 -Wall -Werror -c torneio.c
	gcc -std=c99 -Wall -Werror -c ../arvore.c
	gcc arvore.o torneio.o -lm -o torneio

run:
	./torneio

clean:
	rm *.o
	rm torneio