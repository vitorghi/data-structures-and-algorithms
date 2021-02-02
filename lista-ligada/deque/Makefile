build:
	gcc -std=c99 -Wall -Werror -c deque.c
	gcc -std=c99 -Wall -Werror -c client.c
	gcc client.o deque.o -lm -o deque

run:
	./deque

clean:
	rm *.o
	rm deque