srcname=pacman
binfile=$(srcname).o
$(binfile): main.c game.c game.h pacman.c pacman.h ghost.c ghost.h utility.c utility.h
	gcc main.c game.c pacman.c ghost.c utility.c -o $(binfile) -lncurses -lpthread
clear: 
	rm pacman.o