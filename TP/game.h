// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#ifndef GAME_H
#define GAME_H

typedef struct Tabuleiro Tabuleiro;
struct Tabuleiro {
    char** tab;
    int completed;
};

#include "save.h"

#define NCOL 3
#define NLIN 3
#define TRUE 1
#define FALSE 0

void game();

int menuPrincipal();

void startPlayer();

void startBot();

int finish(Tabuleiro **tab, Save *save);

void regras();

int jogador(int jogada);

void jogada(Tabuleiro** tab, int player, Save* save);

void mostraVencedor(Save save);

int menuJogadas();

int menuFicheiros();

#endif /*GAME_H*/