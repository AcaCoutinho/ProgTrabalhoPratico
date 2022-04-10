#ifndef GAME_H
#define GAME_H

#define TAM 99

typedef struct Tabuleiro tabuleiro;
struct Tabuleiro {
    char** tab;
    int completed;
    char player[TAM];
};

void game();

int menuPrincipal();

void startPlayer();

void startBot();

#endif /*GAME_H*/