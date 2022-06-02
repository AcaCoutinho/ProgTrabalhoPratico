// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#ifndef UTILS_H
#define UTILS_H

#include "game.h"

void initRandom();

int intUniformRnd(int a, int b);

int probEvento(float prob);

int conversorLinColTab(int num);

int conversorLinCol(int num);

void jogadaBot(Tabuleiro **tab);

#endif
