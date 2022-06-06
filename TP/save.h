// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#ifndef SAVE_H
#define SAVE_H

typedef struct Save Save;
struct Save {
    int lin, col;
    int jogada;
    int vencedor;
    Save *nextPlay;
};

#include "game.h"
#include "matdin.h"
#include "utils.h"

void printLista(Save* save);

Save* insereInicio(Save *save, Save s);

void imprimeJogoFile(char *fileName, Save *save);

void imprimeJogadasAnterior(Save *save);

int existsBinaryFile();

void escreveFicheiroBinario(Save *save, int isPlayer);

Save* readBinaryFile(Save* save, int *isPlayer);

void libertaListaLigada(Save *save);

void carregaJogoJogador(Save* save);

void carregaJogoBot(Save* save);

Tabuleiro** carregaTabuleiro(Tabuleiro **tab, Save *save);

#endif /*SAVE_H*/