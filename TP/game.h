// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

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

void regras();

int jogador(int jogada);

void jogada(Tabuleiro** tab, int player);

#endif /*GAME_H*/