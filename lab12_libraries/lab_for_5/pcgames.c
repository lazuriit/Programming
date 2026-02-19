#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcgames.h"

void fillGames(struct Game games[]) {

    const char *titles[10] = {
        "The Witcher 3",
        "GTA V",
        "Baldur's Gate 3",
        "Cyberpunk 2077",
        "Red Dead Redemption 2",
        "The Last of Us",
        "Dying Light",
        "Dark Souls III",
        "Elden Ring",
        "God of War"
    };

    const char *genres[6] = {
        "RPG", "Action", "Sandbox",
        "Shooter", "Adventure", "MOBA"
    };

    for (int i = 0; i < N; i++) {
        strcpy(games[i].title, titles[i % 10]);
        strcpy(games[i].genre, genres[rand() % 6]);
        games[i].year = 2015 + (i % 10);
        games[i].rating = 70 + rand() % 31;
    }
}

void printGames(struct Game games[]) {

    int limit = N;

    if (N > 100)
        limit = 10;

    printf("---------------------------------------------------------------\n");
    printf("| %-25s | %-12s | %-6s | %-7s |\n",
           "Название", "Жанр", "Год", "Рейтинг");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < limit; i++) {
        printf("| %-25s | %-12s | %-6d | %-7d |\n",
               games[i].title,
               games[i].genre,
               games[i].year,
               games[i].rating);
    }

    if (N > 100)
        printf("... (показаны первые 10 элементов из %d)\n", N);

    printf("---------------------------------------------------------------\n\n");
}

void selectionSortByRating(struct Game games[]) {

    struct Game temp;

    for (int i = 0; i < N - 1; i++) {

        int minIndex = i;

        for (int j = i + 1; j < N; j++) {
            if (games[j].rating < games[minIndex].rating) {
                minIndex = j;
            }
        }

        if (minIndex != i) {
            temp = games[i];
            games[i] = games[minIndex];
            games[minIndex] = temp;
        }
    }
}
