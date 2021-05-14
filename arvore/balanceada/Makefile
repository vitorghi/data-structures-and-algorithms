build:
	gcc -std=c99 -Wall -Werror -c red-black-tree.c
	gcc -std=c99 -Wall -Werror -c main.c
	gcc main.o red-black-tree.o -lm -o red-black-tree

run:
	./red-black-tree

clean:
	rm *.o
	rm red-black-tree