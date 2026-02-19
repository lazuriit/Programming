#ifndef _PCGAMES_H_
#define _PCGAMES_H_

#define N 10000

struct Game {
    char title[40];
    char genre[20];
    int year;
    int rating;
};

void fillGames(struct Game games[]);
void printGames(struct Game games[]);
void selectionSortByRating(struct Game games[]);

#endif
