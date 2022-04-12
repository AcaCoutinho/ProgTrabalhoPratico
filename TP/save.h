// Trabalho Pratico Programacao - LEI
// DEIS-ISEC 2021-2022

#ifndef SAVE_H
#define SAVE_H

#include "game.h"

typedef struct Save Save;
struct Save {
    Celula tab;
    int* nextPlay;
};

int fileExists();

#endif /*SAVE_H*/