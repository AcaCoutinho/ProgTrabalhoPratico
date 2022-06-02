// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#include "matdin.h"

void libertaMat(char** p, int nLin){

    int i;

    for(i=0; i<nLin; i++)
        free(p[i]);
    free(p);
}

char** criaMat(int nLin, int nCol){
    char **p = NULL;
    int i, j;

    p = malloc(sizeof(char*) * nLin);
    if(p == NULL)
        return NULL;

    for(i=0; i<nLin; i++){
        p[i] = malloc(sizeof(char) * nCol);
        if(p[i] == NULL){
            libertaMat(p, i-1);
            return NULL;
        }
        for(j=0; j<nCol; j++)
            p[i][j] = '_';
    }
    return p;
}

void setPos(char **p, int x, int y, char c){
    p[x][y] = c;
}

char getPos(char **p, int x, int y){
    return p[x][y];
}

void mostraMat(char **p, int nLin, int nCol){
    int i,j;

    for(i=0; i<nLin; i++){
        for(j=0; j<nCol; j++)
            printf("%c\t", p[i][j]);
        putchar('\n');
    }
}

Tabuleiro** inicializaTabuleiro(int nLinTab, int nColTab){
    Tabuleiro** aux;

    aux = malloc(sizeof(Tabuleiro) * nLinTab);
    if(aux == NULL){
        printf("Erro!");
        return NULL;
    }
    for(int i = 0; i < nLinTab; i++){
        aux[i] = malloc(sizeof(Tabuleiro) * nColTab);
        if(aux[i] == NULL){
            printf("Erro!");
            return NULL;
        }
    }

    for(int i = 0; i < nLinTab; i++){
        for(int j = 0; j < nColTab; j++){
            aux[i][j].tab = criaMat(NLIN, NCOL);
            aux[i][j].completed = 0;
        }
    }

    return aux;
}

void mostraTabuleiro(Tabuleiro** tab, int nLin, int nCol) {
    printf("\n---------------------------------\n");
    for(int i = 0; i < NLIN; i++){
        for(int k = 0; k < 4; k++){
            for(int j = 0; j < NCOL; j++){
                switch (k) {
                    case 0:
                        imprimeLinhaTabuleiro(tab[i][j], k);
                        break;
                    case 1:
                        imprimeLinhaTabuleiro(tab[i][j], k);
                        break;
                    case 2:
                        imprimeLinhaTabuleiro(tab[i][j], k);
                        break;
                    case 3:
                        printf("-----------");
                        break;
                }
            }
            printf("\n");
        }
    }
}

void imprimeLinhaTabuleiro(Tabuleiro tab, int linha){
    printf("|");
    for(int i = 0; i < NCOL; i++){
        printf(" %c ", tab.tab[linha][i]);
    }
    printf("|");
}

void verificaCompleto(Tabuleiro tab){
    if(tab.tab[0][0] == tab.tab[1][1] && tab.tab[1][1] == tab.tab[2][2] && tab.completed != 0){
        if(tab.tab[0][0] == 'O')
            tab.completed = 1;
        if(tab.tab[0][0] == 'X')
            tab.completed = 2;
    }

    for(int i = 0; i < 3; i++){

    }
}