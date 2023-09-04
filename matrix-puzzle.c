#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

void createMatrix(int arr[3][3])
{           
    int n=8;
    int num[n],i,j;
    for(i=0;i<8;i++){                      //num array containing 8 nos.
        num[i]=i+1;
    }
    srand(time(NULL));                     //for random no. generation
    
    int lastIndex = n-1;
    int index;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){                            
            if(lastIndex >= 0){
                index = rand() % (lastIndex+1);      //we get index from 0 to 7 by doing modulus with 8
                arr[i][j] = num[index];              //and no. at that index goes in 2-d array
                num[index] = num[lastIndex--];       //now,that no.(in num array) is replaced with lastIndex no. to avoid repetitions
            }
        }
    }
    arr[i-1][j-1] = 0;                               //last no. is 0 (data is zero but we display space there)
}

void showMatrix(int arr[][3])
{                    
    int i,j;
    printf("------------------\n");
    for(i=0;i<3;i++){
        printf("|");
        for(j=0;j<3;j++){
            if(arr[i][j] != 0){
                printf("%2d  | ",arr[i][j]);
            }
            else{
                printf("    | ");                     //to show last no. empty 
            }
        }
        printf("\n");
    }
    printf("------------------\n");
}

int winner(int arr[][3])                               //check winning by this function
{
    int i,j;
    int k = 1;                                         //k is the 3rd variable that contains expected values
    for(i=0;i<3;i++){
        for(j=0;j<3;j++,k++){
            if(arr[i][j]!=k && k!=9)
               break;
        }
        if(j<3){
            break;
        }
    }
    if(j<3){
        return 0;
    }
    return 1;
}

void swap(int *x,int *y)                              //swap function to swap two nos.
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
    printf("");
}

int readEnteredKey()                                 
{
    char c;
    c = _getch();                      //_getch(present in conio.h) reads the single character
    if(c==-32){                        //it indicates that a special key like arrow key or function key is pressed
        c = _getch();
    }
    return c;                          //_getch() returns the integer value which is the ascii code of the character used
}
  
int shiftUp(int arr[][3])
{
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arr[i][j] == 0){
                break;
            }
        }
        if(j<3)
           break;
    }
    if(i==2){                           //shifting not possible
        return 0;
    }
    swap(&arr[i][j],&arr[i+1][j]);      //Successfully swapped two nos.
    return 1;                           //Success
}

int shiftDown(int arr[][3])
{
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arr[i][j] == 0){
                break;
            }
        }
        if(j<3)
           break;
    }
    if(i==0){                           //shifting not possible
        return 0;
    }
    swap(&arr[i][j],&arr[i-1][j]);      //Successfully swapped two nos.
    return 1;                           //Success
}

int shiftRight(int arr[][3])
{
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arr[i][j] == 0){
                break;
            }
        }
        if(j<3)
           break;
    }
    if(j==0){                           //shifting not possible
        return 0;
    }
    swap(&arr[i][j],&arr[i][j-1]);      //Successfully swapped two nos.
    return 1;                           //Success
}

int shiftLeft(int arr[][3])
{
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(arr[i][j] == 0){
                break;
            }
        }
        if(j<3)
           break;
    }
    if(j==2){                           //shifting not possible
        return 0;
    }
    swap(&arr[i][j],&arr[i][j+1]);      //Successfully swapped two nos.
    return 1;                           //Success
}

void gameRule(int arr[][3])
{
    system("cls");
    printf("\t\t  MATRIX PUZZLE\n"); 
    printf("\n");
    printf("  RULES OF THE GAME : \n");
    printf("\n1. You can move only one step at a time by arrow keys. ");
    printf("\n\tMove Up   : By Up arrow key");
    printf("\n\tMove Down : By Dowm arrow key");
    printf("\n\tMove Left : By Left arrow key");
    printf("\n\tMove Right: By Right arrow key");

    printf("\n2. You can move number at empty position only.");
    printf("\n3. For each valid move, total number of moves will decrease by 1.\n");
    printf("4. Winning Situation: \n");
    printf("   Numbers in a 3*3 matrix should be in order 1 to 8. ");

    printf("\n5. You can exit the game at any time by pressing 'E' or 'e' ");
    printf("\n   Try to win the game in minimum number of moves.\n");

    printf("\nEnter any key to start.....   ");
    int x = readEnteredKey();
}

int main()
{
    int arr[3][3];                      //matrix
    int maxTry = 100;                   //maximum moves

    char name[20];
    printf("Player Name: ");
    gets(name);

    system("cls");                      //to clear console screen(present in <stdlib.h> library)

    while(1){
        createMatrix(arr); 
        gameRule(arr);      

        while(!winner(arr)){             //checking for winning situation
            system("cls");
            if(!maxTry){                //for remaining 0 move
                break;
            }
            printf("\n\n Player Name: %s , Moves Remaining: %d\n\n",name,maxTry);
            showMatrix(arr);

            int key = readEnteredKey();                   //it reads the ascii value of entered key by user
            switch(key){
                case 101:                                                        //101 is ascii value of e
                case 69:                                                         //69 is ascii value of E
                    printf("\t\t\t\t\t\nThanks for Playing! \n");
                    printf("\nPress 'Enter' to exit the game \n");
                    key = readEnteredKey();
                    return 0;                             //function ends means loop ends and it will exit the game

                case 72:                                  //72 is scan code for up arrow
                    if(shiftUp(arr))
                        maxTry--;
                    break;  
                case 80:                                  //80 is scan code for down arrow
                    if(shiftDown(arr)) 
                        maxTry--;
                    break;  
                case 77:                                  //77 is scan code for right arrow
                    if(shiftRight(arr))
                        maxTry--;
                    break;  
                case 75:                                  //75 is scan code for left arrow
                    if(shiftLeft(arr))
                        maxTry--;
                    break;   
                default:
                    printf("\n\n\t\tNot Allowed \t");     
            }
        }
        showMatrix(arr);

        if(!maxTry)
            printf("\n\a    YOU LOSE!          \a\a\n");
        else
            printf("\n\a!!!!!!!!Congratulations %s for winning this game!!!!!!!!\a\n",name);

        fflush(stdin);                                      //clear the buffer

        char check;
        printf("\nWant to play again? \n");
        printf("Enter 'y/Y' to play again: ");
        scanf("%c",&check);

        if((check!='y') && (check!='Y'))                
            break;
        maxTry=50;      
    }
    return 0;
}
