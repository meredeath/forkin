all: forks.c
	gcc forks.c
run: all
	./a.out
