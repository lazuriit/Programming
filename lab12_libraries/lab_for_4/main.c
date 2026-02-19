#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pcgames.h"

#define N 10

int main() {

    srand(time(NULL));

    struct Game games[N];

    fillGames(games);

    printf("Массив ДО сортировки по рейтингу:\n\n");
    printGames(games);

    selectionSortByRating(games);

    printf("Массив ПОСЛЕ сортировки по рейтингу:\n\n");
    printGames(games);

    return 0;
}

