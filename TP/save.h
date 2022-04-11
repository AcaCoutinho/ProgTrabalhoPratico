#ifndef SAVE_H
#define SAVE_H

#include "game.h"

typedef struct Save Save;
struct Save {
    Tabuleiro tab;
    int* nextPlay;
};

int fileExists();

#endif /*SAVE_H*/