build:
	gcc -std=c99 -Wall -Werror -c ../pilha.c
	gcc -std=c99 -Wall -Werror -c notacoes.c
	gcc -std=c99 -Wall -Werror -c ../../lista-ligada/listaligada.c
	gcc listaligada.o notacoes.o pilha.o -lm -o notacoes

run:
	./notacoes

clean:
	rm *.o
	rm notacoes