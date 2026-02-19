Компиляция, линковка и запуск
```
gcc pcgames.c -c
ar rc libPC_GAMES.a pcgames.o
gcc main.c -o static_exe -L. -lPC_GAMES
./static_exe
```
