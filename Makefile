all:
	gcc -c -Wall *.c
	gcc -o sig_burger *.o

clear:
	rm *.o sig_burger