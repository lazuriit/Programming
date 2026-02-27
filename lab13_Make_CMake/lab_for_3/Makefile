.PHONY: clean

all: static_exe

static_exe: src/main.c libPC_GAMES.a
	gcc src/main.c -o static_exe -L. -lPC_GAMES -I ./include

libPC_GAMES.a: pcgames.o
	ar rc libPC_GAMES.a pcgames.o

pcgames.o: src/pcgames.c
	gcc -c src/pcgames.c -o pcgames.o -I ./include

clean:
	rm -rf *.o *.a static_exe

run: all
	./static_exe