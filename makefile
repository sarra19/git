#makefile pandemic
CFLAGS =-w -O2 -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf

#cible:dependances
#	(tabulation) commandes

all: main.o
	g++ main.o -o prog $(CFLAGS)
		
#
main.o :main.c
	g++ -c main.c -o main.o

#
#clean fichiers obj
clean:
	rm -rf *.o
#
