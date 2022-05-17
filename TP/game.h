#ifndef GAME_H
#define GAME_H

#define NCOL 3
#define NLIN 3
#define TRUE 1
#define FALSE 0

typedef struct Tabuleiro Tabuleiro;
struct Tabuleiro {
    char** tab;
    int completed;
};

void game();

int menuPrincipal();

void startPlayer();

void startBot();

int finish(Tabuleiro **tab);

#endif /*GAME_H*/