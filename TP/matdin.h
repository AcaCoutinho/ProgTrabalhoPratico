// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#ifndef MATDIN_H
#define MATDIN_H

#include <stdlib.h>
#include <stdio.h>
#include "game.h"

void libertaMat(char** p, int nLin);

char** criaMat(int nLin, int nCol);

void mostraMat(char **p, int nLin, int nCol);

void setPos(char **p, int x, int y, char c);

char getPos(char **p, int x, int y);

Tabuleiro** inicializaTabuleiro(int nLin, int nCol);

void mostraTabuleiro(Tabuleiro** tab, int nLin, int nCol);

void imprimeLinhaTabuleiro(Tabuleiro tab, int linha);

int verificaTabuleiro(Tabuleiro tab);

int verificaCompletoTab(Tabuleiro tab);

void libertaTabuleiro(Tabuleiro **tab, int nLin);

void completaTabuleiro (char** tab, int jogador);

#endif /*MATDIN_H*/