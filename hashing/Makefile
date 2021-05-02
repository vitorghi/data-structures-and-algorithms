build:
	gcc -std=c99 -Wall -Werror -c hashtable.c
	gcc -std=c99 -Wall -Werror -c main.c
	gcc main.o hashtable.o -lm -o hashtable

run:
	./hashtable

clean:
	rm *.o
	rm hashtable