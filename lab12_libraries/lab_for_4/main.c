#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "pcgames.h"

struct Game games[N];

int main() {
    srand(time(NULL));

    fillGames(games);

    printf("Массив ДО сортировки:\n\n");
    printGames(games);

    selectionSortByRating(games);

    printf("Массив ПОСЛЕ сортировки:\n\n");
    printGames(games);

    return 0;
}
