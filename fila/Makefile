build:
	gcc -std=c99 -Wall -Werror -c fila.c
	gcc -std=c99 -Wall -Werror -c aula14.c
	gcc -std=c99 -Wall -Werror -c ../lista-ligada/listaligada.c
	gcc listaligada.o aula14.o fila.o -lm -o fila

run:
	./fila

clean:
	rm *.o
	rm fila