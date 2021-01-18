all: frequency Rfrequency
	

frequency: valg.o
	gcc -Wall valg.o -o frequency

Rfrequency: rvalg.o
	gcc -Wall rvalg.o -o "frequency r"

valg.o: valg.c
	gcc -Wall -c valg.c

rvalg.o: rvalg.c
	gcc -Wall -c rvalg.c

clean:
	rm -f *o frequency "frequency r"
