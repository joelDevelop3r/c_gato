#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum status{
    xWin, // 0
    oWin,
    tie,
    undefined
} STATUS;
typedef enum box{
    x, //0
    o,
    empty
}BOX;
typedef enum player{
    X,
    O
} PLAYER;

typedef struct gato{
    BOX game[9];
    STATUS gameStatus;
    BOX nextPlayer; //determine who is next to choose 'x' or 'o'
    int depth;
    int numberOfForks;
    struct gato* forks;
    int minmax;
}GATO;
typedef GATO* gatoPointer;

/** @brief This function get the number of posibles forks of cat.
 * @param game is an array that describe a cat game.
 * @return [int 9-1] number of posibles fork.
 */
int numberOfForks(const BOX game[9]){
    int forks = 0;
    for (int i=0; i<9; i++){    
        if(game[i] == empty){
            //New cat fork
            forks++;
        }
    }
    return forks;
}
/** @brief This function find if the cat is a valid game.
 * @param game is an array that describe a cat game.
 * @return [100] if x win.
 * [-1] if is an invalid cat.
 * [0] if cat is valid.
 */
int isValid(const BOX game[9]){
    int xCounter=0;
    int oCounter=0;
    for(int i=0; i<9; i++){
        if(game[i]==x){
            xCounter++;
        }else if(game[i]==o){
            oCounter++;
        }
    }

    if((xCounter-oCounter)>1){
        return -1;
    }
    return 0;
}
/** @brief This function get the minmax value of cat.
 * @param gato is a pointer to cat object.
 * @return [100] if x win.
 * [-100] if o win.
 * [int] the minmax value.
 */
int MINMAX(gatoPointer gato){
    int xCounter=0;
    int oCounter=0;
    if(gato->gameStatus == xWin){
        gato->minmax=100;
        return 100;
    }else if(gato->gameStatus == oWin){
        gato->minmax=-100;
        return -100;
    }

    //Column 1
    if(
        (gato->game[0]==empty || gato->game[0]==x)
        &&
        (gato->game[3]==empty || gato->game[3]==x)
        &&
        (gato->game[6]==empty || gato->game[6]==x)
        )
    {
        xCounter++;
    }
    //Column 2
    if(
        (gato->game[1]==empty || gato->game[1]==x)
        &&
        (gato->game[4]==empty || gato->game[4]==x)
        &&
        (gato->game[7]==empty || gato->game[7]==x)
        )
    {
        xCounter++;
    }
    //Column 3
    if(
        (gato->game[2]==empty || gato->game[2]==x)
        &&
        (gato->game[5]==empty || gato->game[5]==x)
        &&
        (gato->game[8]==empty || gato->game[8]==x)
        )
    {
        xCounter++;
    }
    //Row 1
    if(
        (gato->game[0]==empty || gato->game[0]==x)
        &&
        (gato->game[1]==empty || gato->game[1]==x)
        &&
        (gato->game[2]==empty || gato->game[2]==x)
        )
    {
        xCounter++;
    }
    //Row 2
    if(
        (gato->game[3]==empty || gato->game[3]==x)
        &&
        (gato->game[4]==empty || gato->game[4]==x)
        &&
        (gato->game[5]==empty || gato->game[5]==x)
        )
    {
        xCounter++;
    }
    //Row 3
    if(
        (gato->game[6]==empty || gato->game[6]==x)
        &&
        (gato->game[7]==empty || gato->game[7]==x)
        &&
        (gato->game[8]==empty || gato->game[8]==x)
        )
    {
        xCounter++;
    }

    //Diagonal 1
    if(
        (gato->game[6]==empty || gato->game[6]==x)
        &&
        (gato->game[4]==empty || gato->game[4]==x)
        &&
        (gato->game[2]==empty || gato->game[2]==x)
        )
    {
        xCounter++;
    }
    // Diagonal 2
    if(
        (gato->game[0]==empty || gato->game[0]==x)
        &&
        (gato->game[4]==empty || gato->game[4]==x)
        &&
        (gato->game[8]==empty || gato->game[8]==x)
        )
    {
        xCounter++;
    }

    //Column 1
    if(
        (gato->game[0]==empty || gato->game[0]==o)
        &&
        (gato->game[3]==empty || gato->game[3]==o)
        &&
        (gato->game[6]==empty || gato->game[6]==o)
        )
    {
        oCounter++;
    }
    //Column 2
    if(
        (gato->game[1]==empty || gato->game[1]==o)
        &&
        (gato->game[4]==empty || gato->game[4]==o)
        &&
        (gato->game[7]==empty || gato->game[7]==o)
        )
    {
        oCounter++;
    }
    //Column 3
    if(
        (gato->game[2]==empty || gato->game[2]==o)
        &&
        (gato->game[5]==empty || gato->game[5]==o)
        &&
        (gato->game[8]==empty || gato->game[8]==o)
        )
    {
        oCounter++;
    }
    //Row 1
    if(
        (gato->game[0]==empty || gato->game[0]==o)
        &&
        (gato->game[1]==empty || gato->game[1]==o)
        &&
        (gato->game[2]==empty || gato->game[2]==o)
        )
    {
        oCounter++;
    }
    //Row 2
    if(
        (gato->game[3]==empty || gato->game[3]==o)
        &&
        (gato->game[4]==empty || gato->game[4]==o)
        &&
        (gato->game[5]==empty || gato->game[5]==o)
        )
    {
        oCounter++;
    }
    //Row 3
    if(
        (gato->game[6]==empty || gato->game[6]==o)
        &&
        (gato->game[7]==empty || gato->game[7]==o)
        &&
        (gato->game[8]==empty || gato->game[8]==o)
        )
    {
        oCounter++;
    }

    //Diagonal 1
    if(
        (gato->game[6]==empty || gato->game[6]==o)
        &&
        (gato->game[4]==empty || gato->game[4]==o)
        &&
        (gato->game[2]==empty || gato->game[2]==o)
        )
    {
        oCounter++;
    }
    // Diagonal 2
    if(
        (gato->game[0]==empty || gato->game[0]==o)
        &&
        (gato->game[4]==empty || gato->game[4]==o)
        &&
        (gato->game[8]==empty || gato->game[8]==o)
        )
    {
        oCounter++;
    }

    gato->minmax=xCounter-oCounter;
    return xCounter-oCounter;
}
void setMinmaxValues(gatoPointer gato){
    //set the minmax value for terminal node
    if(gato->forks==NULL){
        
        MINMAX(gato);
        return;
    }
    //set the minmax values for all terminal nodes
    for (int i=0; i<gato->numberOfForks; i++){
        setMinmaxValues(gato->forks+i);
    }

    int aux = (gato->forks+0)->minmax;
    int aux2;
    //search for best min max value
    for (int i=0; i<gato->numberOfForks; i++){
        if(gato->nextPlayer==x){
            //select max
            if((gato->forks+i)->minmax > aux){
                aux= (gato->forks+i)->minmax;
            }
        }else{
            //select min
            if((gato->forks+i)->minmax < aux){
                aux= (gato->forks+i)->minmax;
            }
        }
    }
    gato->minmax=aux;
    return;
}
/** @brief This function get the status of cat
 * @param game is an array of 9 BOX elements, who describe a cat.
 * @return [xWin] if x complete a line.
 * [oWin] if o complete a line.
 * [tie] if there is not more empty boxes and anybody wins 
 * [undefined] if there is empty boxes and already anybody wins.
 */
STATUS gatoStatus(const BOX game[9]){
    /*
    * gato[0,1,2,3,4,5,6,7,8]
    * 
    * 0|1|2
    * 3|4|5
    * 6|7|8
    */
    if(
        (game[0]==x && game[1]==x && game[2] == x)
        ||
        (game[3]==x && game[4]==x && game[5] == x)
        ||
        (game[6]==x && game[7]==x && game[8] == x)
        ||
        (game[0]==x && game[4]==x && game[8] == x)
        ||
        (game[6]==x && game[4]==x && game[2] == x)
        ||
        (game[0]==x && game[3]==x && game[6] == x)
        ||
        (game[1]==x && game[4]==x && game[7] == x)
        ||
        (game[2]==x && game[5]==x && game[8] == x)
        ){
            return xWin;
        }
        else if(
        (game[0]==o && game[1]==o && game[2] == o)
        ||
        (game[3]==o && game[4]==o && game[5] == o)
        ||
        (game[6]==o && game[7]==o && game[8] == o)
        ||
        (game[0]==o && game[4]==o && game[8] == o)
        ||
        (game[6]==o && game[4]==o && game[2] == o)
        ||
        (game[0]==o && game[3]==o && game[6] == o)
        ||
        (game[1]==o && game[4]==o && game[7] == o)
        ||
        (game[2]==o && game[5]==o && game[8] == o)
        ){
            return oWin;
        }else{
            //if there is an empty box, the cat is undefined
            for(int i=0; i<9; i++){
                if(game[i]==empty){
                    return undefined;
                }
            }
            //if there is not an empty box, tha cat is over and we get a tie
            return tie;
        }
}


/** @brief This function initialize an object of GATO structure
 * set who is nexte player
 * set the cat matrix
 * set the number of forks posibles
 * set the pointer to an array of objects cat named as forks.
 * @param depth Is the maximun dept for gato tree.
 * @param nextPlayer Is the value of player who moves next.
 * @param gato Is a pointer to GATO structure.
 * @param m Is the address of box vector who define the current values of cat positions.
 * @return [0] if inilization is correct.
 * [-1] if depth is more than expected.
 * [-2] if game is invalid.
 * [-123] if calloc fails.
 */
int gatoInit(int depth, BOX nextPlayer, gatoPointer gato, const BOX m[9], int maxDepth){

    if(isValid(m)!=0){
        return -3;
    }
    gato->gameStatus = gatoStatus(m);
    gato->depth = depth;
    gato->nextPlayer = nextPlayer;
    //aqui va
    gato->game[0]=m[0];
    gato->game[1]=m[1];
    gato->game[2]=m[2];
    gato->game[3]=m[3];
    gato->game[4]=m[4];
    gato->game[5]=m[5];
    gato->game[6]=m[6];
    gato->game[7]=m[7];
    gato->game[8]=m[8];

    gato->numberOfForks=numberOfForks(m);


    if(gato->gameStatus==xWin || gato->gameStatus==oWin || gato->gameStatus==tie || numberOfForks(m)==0 ||maxDepth==0){
        //finish creation of tree
        gato->forks=NULL;
        gato->numberOfForks=0;
        return 0;
    }


    
    gato->forks=(gatoPointer) malloc(gato->numberOfForks*sizeof(GATO));
    if(gato->forks==NULL && gato->numberOfForks!=0){
        //malloc fails
        gato->numberOfForks=0;
        return -123;
    }


    
    //Aux vector get the original game
    
    BOX aux [9];
    int count=0;
    //Recursive Initialize all forks
    for (int i=0; i<9; i++){
        if(gato->game[i]==empty){
            for(int j=0; j<9; j++){
                aux[j]=gato->game[j];
            }
            aux[i] = gato->nextPlayer;
            gatoInit(depth+1, gato->nextPlayer==x?o:x, gato->forks+count, aux, maxDepth-1);
            count++;
        }
    }
    return 0;
}

gatoPointer chooseX(gatoPointer gato){
    if(gato->forks==NULL && gato->numberOfForks==0){
        return gato;
    }
    gatoPointer choosenOne;
    gatoPointer select;
    //set the minmax value for all forks
    setMinmaxValues(gato);
    for (int i=0; i < gato->numberOfForks; i++)
    {
        if(gato->minmax == (gato->forks+i)->minmax){
            return gato->forks+i;
        }
    }
    return NULL;
    
}








