build:
	gcc -std=c99 -Wall -Werror -c ../pilha.c
	gcc -std=c99 -Wall -Werror -c balanceamento.c
	gcc -std=c99 -Wall -Werror -c ../../lista-ligada/listaligada.c
	gcc listaligada.o balanceamento.o pilha.o -lm -o balanceamento

run:
	./balanceamento

clean:
	rm *.o
	rm balanceamento