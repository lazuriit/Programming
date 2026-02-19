#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pcgames.h"

#define N 10

void fillGames(struct Game games[]) {

    const char *titles[N] = {
        "The Witcher 3",
        "GTA V",
        "Baldur's Gate 3",
        "Cyberpunk 2077",
        "Red Dead Redemption 2",
        "The Last of Us",
        "Dying Light",
        "Dark souls III",
        "Elden Ring",
        "God of War"
    };

    const char *genres[] = {
        "RPG",
        "Action",
        "Sandbox",
        "Shooter",
        "Adventure",
        "MOBA"
    };

    int years[N] = {
        2015, 2016, 2017, 2018, 2019, 2020, 2021, 2022, 2023, 2024
    };

    for (int i = 0; i < N; i++) {
        strcpy(games[i].title, titles[i]);
        strcpy(games[i].genre, genres[rand() % 6]);
        games[i].year = years[i];        
        games[i].rating = 70 + rand() % 31;
    }
}

void printGames(struct Game games[]) {
    printf("---------------------------------------------------------------\n");
    printf("| %-33s | %-16s | %-9s | %-7s |\n",
           "Название", "Жанр", "Год", "Рейтинг");
    printf("---------------------------------------------------------------\n");

    for (int i = 0; i < N; i++) {
        printf("| %-25s | %-12s | %-6d | %-7d |\n",
               games[i].title,
               games[i].genre,
               games[i].year,
               games[i].rating);
    }

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