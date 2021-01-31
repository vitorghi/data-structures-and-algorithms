build:
	gcc -std=c99 -Wall -Werror -c pilha.c
	gcc -std=c99 -Wall -Werror -c aula14.c
	gcc -std=c99 -Wall -Werror -c ../lista-ligada/listaligada.c
	gcc listaligada.o aula14.o pilha.o -lm -o pilha

run:
	./pilha

clean:
	rm *.o
	rm pilha