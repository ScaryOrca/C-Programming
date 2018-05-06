all: bst

bst: bst.o driver.o
	gcc -o bst bst.o driver.o

bst.o: bst.c bst.h
	gcc -c bst.c

driver.o: driver.c
	gcc -c driver.c

clean:
	rm *o bst

run:
	./bst
