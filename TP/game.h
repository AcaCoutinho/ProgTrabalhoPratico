// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#ifndef GAME_H
#define GAME_H


typedef struct Celula Celula;
struct Celula {
    char** tab;
    int completed;
    int player;
};

void game();

int menuPrincipal();

void startPlayer();

void startBot();

void startMemoria();

Celula** iniciaTab();

void showTab(Celula** aux);

int finished();

#endif /*GAME_H*/