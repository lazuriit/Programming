#ifndef _PCGAMES_H_
#define _PAGAMES_H_

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