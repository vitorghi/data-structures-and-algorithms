build:
	gcc -std=c99 -Wall -Werror -c ../heap/heap-max.c
	gcc -std=c99 -Wall -Werror -c heapsort.c
	gcc heapsort.o heap-max.o -lm -o heapsort

run:
	./heapsort

clean:
	rm *.o
	rm heapsort