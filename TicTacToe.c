#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int turn=9;
char your_turn[9] = {' ',' ',' ',' ',' ',' ',' ',' ',' '};

void game_board(){
    printf("\t Tic Tac Toe !");
    printf("\n Player 1 (X)  -  Player 2 (O)\n");
    printf("    :    :    \n");
    printf("  %c :  %c :  %c  \n", your_turn[0], your_turn[1], your_turn[2]);
    printf("____:____:____\n");
    printf("    :    :    \n");
    printf("  %c :  %c :  %c  \n", your_turn[3], your_turn[4], your_turn[5]);
    printf("____:____:____\n");
    printf("    :    :    \n");
    printf("  %c :  %c :  %c  \n", your_turn[6], your_turn[7], your_turn[8]);
    printf("    :    :    \n");
}
int win_analysis(){
    for(int i=0; i<9; i+=3){
        if((your_turn[i] != 32) && (your_turn[i]==your_turn[i+1] && your_turn[i+1]==your_turn[i+2]))
            return 1;
    }
    for(int i=0; i<3; i+=1){
        if((your_turn[i] != 32) && (your_turn[i]==your_turn[i+3] && your_turn[i+3]==your_turn[i+6]))
            return 1;
    }
    if((your_turn[0] != 32) && (your_turn[0]==your_turn[4] && your_turn[4]==your_turn[8]))
        return 1;
    if((your_turn[2] != 32) && (your_turn[2]==your_turn[4] && your_turn[4]==your_turn[6]))
        return 1;
    return 0;
}
void main(){
    int position, check;
    char player;
    game_board();
    while(turn--){
        player = ((turn+1)%2)? 'X' : 'O';
        printf("Player %d's turn, enter a number between 1 to 9 to place %c : ", (turn%2)+1, player);
        scanf("%d", &position);
        if(your_turn[position-1]==32 && (position>0) && (position<=9)){
            your_turn[position-1] = player;
        }
        else{
            printf("Invalid\n");
            turn++;
        }
        game_board();
        if(win_analysis()){
            printf("Hurry! Player %d Won!", (turn%2)+1);
            break;
        }
        else {
            if(turn==0)
                printf("Oops! It's Draw, Better Luck Next Time");
        }
    }
    printf("\nThank You! Hope You Enjoyed the Game ;-)");
    getch();
}