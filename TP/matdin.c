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
            aux[i][j].tab = criaMat(3, 3);
            aux[i][j].completed = 0;
        }
    }

    return aux;
}

void mostraTabuleiro(Tabuleiro** tab, int nLin, int nCol){
    for(int i = 0; i < nLin; i++){
        for(int j = 0; j < nCol; j++){
            mostraMat(tab[i][j].tab, nLin, nCol);
        }
    }
}