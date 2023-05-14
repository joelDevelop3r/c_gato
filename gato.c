#include <stdio.h>
#include <stdlib.h>
#include "gato.h"
#define _DEPTH 8

int main(){
    GATO currentGame;
    gatoPointer root;
    BOX game[9] = { empty,  empty,  empty,
                    empty,  empty,  empty,
                    empty,  empty,  empty};

    if(gatoInit(0,x, &currentGame, game, _DEPTH)!=0){
        printf("\nInvalid Game");
        return -1;
    }
    root = chooseX(&currentGame);
    
    for(int i =0; i<currentGame.numberOfForks; i++){
        printf("\t %d",(currentGame.forks+i)->minmax);
    }
    printf("\n%d",root->minmax);



    printf("\n %s\n\n", root->gameStatus==undefined?"Juego Indefinido": root->gameStatus==xWin?"X gana":root->gameStatus==oWin?"O gana":"Empate");
    for(int i=0; i<9; i++){
        if(i==3 || i==6){
            printf("\n");
        }
        printf("\t%s", root->game[i]==empty?"empty": root->game[i]==x?"X":"O");
    }


    return 0;
}