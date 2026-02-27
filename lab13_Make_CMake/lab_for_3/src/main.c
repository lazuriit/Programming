#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include "pcgames.h"

struct Game games[N];

int main() {

    srand(time(NULL));

    fillGames(games);

    printf("Массив ДО сортировки:\n\n");
    printGames(games);

    struct timeval start, end;

    gettimeofday(&start, NULL);

    selectionSortByRating(games);

    gettimeofday(&end, NULL);

    printf("Массив ПОСЛЕ сортировки:\n\n");
    printGames(games);

    double time_spent =
        (end.tv_sec - start.tv_sec) +
        (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("Размер данных: %d\n", N);
    printf("Время сортировки: %.6f секунд\n\n", time_spent);

    return 0;
}
