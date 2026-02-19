# gcc pcgames.c -c -fPIC
# gcc --shared pcgames.o -o libPC_GAMES.so
# gcc main.c -o dynamic_exe -L. -lPC_GAMES -Wl,-rpath,.
# ./dynamic_exe
