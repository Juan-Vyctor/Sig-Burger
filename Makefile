all:
	gcc -Wall -c include/*.h
	gcc -c -Wall -c *.c  -I include
	gcc -o sig_burger *.o

clear:
	rm *.o sig_burger