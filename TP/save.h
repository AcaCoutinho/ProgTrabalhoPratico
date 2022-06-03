// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#ifndef SAVE_H
#define SAVE_H

#include "game.h"
#include "matdin.h"

typedef struct Save Save;
typedef struct Tabuleiro Tabuleiro;
struct Save {
    int lin, col;
    int jogada;
    int vencedor;
    Save *nextPlay;
};

int fileExists();

#endif /*SAVE_H*/