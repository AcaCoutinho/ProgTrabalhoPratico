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

    aux = malloc(sizeof (Tabuleiro) * NLIN);
    if(aux == NULL){
        printf("Erro na criacao do tabuleiro!");
        return NULL;
    }
    for(int i = 0; i < NLIN; i++){
        aux[i] = malloc(sizeof (Tabuleiro) * NCOL);
        if(aux[i] == NULL){
            libertaTabuleiro(aux, i - 1);
            printf("Erro na criacao do tabuleiro!!");
            return NULL;
        }
    }

    for(int i = 0; i < NLIN; i++){
        for(int j = 0; j < NCOL; j++){
            aux[i][j].tab = criaMat(3, 3);
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
                    default:
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

int verificaTabuleiro(Tabuleiro tab){
    if(tab.tab[0][0] == tab.tab[1][1] && tab.tab[1][1] == tab.tab[2][2]
    && tab.tab[0][0] != '_'){
        if(tab.tab[0][0] == 'O'){
            return 1;
        } else {
            return 2;
        }
    }

    for(int i = 0; i < 3; i++){
        if(tab.tab[0][i] == tab.tab[1][i] && tab.tab[1][i] == tab.tab[2][i]
        && tab.tab[0][i] != '_'){
            if(tab.tab[0][i] == 'O'){
                return 1;
            } else {
                return 2;
            }
        }
        if(tab.tab[i][0] == tab.tab[i][1] && tab.tab[i][1] == tab.tab[i][2]
           && tab.tab[i][0] != '_'){
            if(tab.tab[i][0] == 'O'){
                return 1;
            } else {
                return 2;
            }
        }
    }

    return 0;
}

int verificaCompletoTab(Tabuleiro tab){
    int count = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(tab.tab[i][j] == '_'){
                count += 1;
            }
        }
    }
    return count;
}

void libertaTabuleiro(Tabuleiro **tab, int nLin){
    for(int i = 0; i < NLIN; i++)
        for(int j = 0; j < NCOL; j++)
            libertaMat(tab[i][j].tab, 3);

    for(int i = 0; i < nLin; i++)
        free(tab[i]);
    free(tab);
}