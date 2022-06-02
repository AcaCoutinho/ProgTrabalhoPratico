// Trabalho Pratico Programacao - LEI
// Trabalho de Programacao 2021/2022
// Acacio Agabalayeve Coutinho 2020141948
// DEIS-ISEC 2021-2022

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "utils.h"

void initRandom(){
    srand(time(NULL));
}

int intUniformRnd(int a, int b){
    return a + rand()%(b-a+1);
}

int probEvento(float prob){
    return prob > ((float)rand()/RAND_MAX);
}

int conversorLinColTab(int num){
    if(num == 0 || num == 1 || num == 2){
        return 0;
    } else if (num == 3 || num == 4 || num == 5) {
        return 1;
    } else {
        return 2;
    }
}

int conversorLinCol(int num){
    if(num == 0 || num == 3 || num == 6){
        return 0;
    } else if (num == 1 || num == 4 || num == 7) {
        return 1;
    } else {
        return 2;
    }
}

void jogadaBot(Tabuleiro **tab){

}