# Makefile for Cards program
# Marcel Riera - For COP4338

FILES = MainCards.c CardsValidation.c CardsFunctions.c
OUT = CardsShuffle.out

build: $(FILES)
	gcc $(FILES) -o $(OUT)
	
clean: 
	rm -f *.o core

rebuild: clean build