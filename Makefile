all:
	gcc -c -Wall *.c
	gcc -o main *.o

clear:
	rm *.o main