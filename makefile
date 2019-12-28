srcname=pacman
binfile=$(srcname).o
$(binfile): main.c game.c game.h pacman.c pacman.h utility.c utility.h
	gcc main.c game.c pacman.c utility.c -o $(binfile) -lncurses -lpthread