HEADERS = funkcje.h
.PHONY: Game_of_Life clean
 
Game_of_Life:	main.o funkcje.o
	cc   main.o funkcje.o -lpng -o Game_of_Life

main.o:	main.c funkcje.c $(HEADERS)
	cc -c -lpng  main.c -o main.o

funkcje.o:	funkcje.c $(HEADERS)
	cc -c funkcje.c -lpng -o funkcje.o


clean:
	rm *.o
	rm *.png
