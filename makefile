all: frequency
	

frequency: valg.o
	gcc -Wall valg.o -o frequency

valg.o: valg.c
	gcc -Wall -c valg.c

clean:
	rm -f *o frequency
