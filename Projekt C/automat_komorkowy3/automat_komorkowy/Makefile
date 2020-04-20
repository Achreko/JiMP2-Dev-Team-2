HEADERS = funkcje.h
.PHONY: generuj clean
 
generuj:	main.o funkcje.o
	cc -o generuj main.o funkcje.o

main.o:	main.c funkcje.c $(HEADERS)
	cc -c main.c -o main.o

funkcje.o:	funkcje.c $(HEADERS)
	cc -c funkcje.c -o funkcje.o


clean:
	rm *.o
