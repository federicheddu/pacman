srcname=pacman
binfile=$(srcname).o
$(binfile): main.c gioco.c gioco.h pacman.c pacman.h ghosts.c ghosts.h
	gcc main.c gioco.c pacman.c ghosts.c -lncurses -o $(binfile)