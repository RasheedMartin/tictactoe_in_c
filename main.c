#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

/*
 * Welcome to my TicTacToe Game
 */
typedef struct{
    char playPiece;
    char name[9];

}Player;

void Board(const char *choices);

bool userSelection(char *choices, const Player *p1, int *pInt);
void play(char *choices, const Player* p1, const Player* p2);
bool checkWinner(const char *choices);



int main() {
    char choices[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    printf("Welcome to TicTacToe!!!\n\n");
    Board(choices);

    // Initializing Players
    Player player1, player2;
    char name[100];
    strcpy(player1.name, "Rasheed");
    player1.playPiece = 'O';
    strcpy(player2.name, "CPU");
    player2.playPiece = 'X';
    play( (char *) &choices, &player1, &player2);

    return 0;
}

void Board(const char *choices){
    for(int i = 0; i < 9;){
        printf("|  %c  |  %c  |  %c  |\n", choices[i], choices[i+1], choices[i+2]);
        i+=3;
    }

}
void play(char *choices, const Player* p1, const Player* p2){
    int count = 0;
    int *ptr = &count;
    while(1){
        if(userSelection(choices, p1, (int *) ptr)){
            break;
        }
        else if(count > 8){
            printf("No one won!!");
            break;
        }
        else if(userSelection(choices, p2, (int *) ptr)){
            break;
        }
    }


}
bool checkWinner(const char *choices){
    if(     ((choices[0] == choices[1]) && (choices[1] == choices[2])) ||
            ((choices[3] == choices[4]) && (choices[4] == choices[5])) ||
            ((choices[6] == choices[7]) && (choices[7] == choices[8])) ||
            ((choices[0] == choices[3]) && (choices[3] == choices[6])) ||
            ((choices[1] == choices[4]) && (choices[4] == choices[7])) ||
            ((choices[2] == choices[5]) && (choices[5] == choices[8])) ||
            ((choices[0] == choices[4]) && (choices[4] == choices[8])) ||
            ((choices[2] == choices[4]) && (choices[4] == choices[6]))){
        return true;
    }
    else{
        return false;
    }
}

bool userSelection(char *choices, const Player *p1, int *pInt) {
    int choice;
    (*pInt)++;
    // Check to make sure we are not overriding pieces
    int temp = 0;
    do {
        printf("\nYour Turn %s! Make your Move\n", p1->name);
        scanf("%d", &choice);
        temp = choice;
    }while(choices[choice - 1] == 'X' || choices[choice - 1] == 'O' || ((choice = getchar()) != '\n' && choice != EOF));
    choices[temp - 1] = p1->playPiece;

    bool winner = checkWinner(choices);
    if(winner){
        printf("Congratulations %s, You won!\n", p1->name);
        Board(choices);
        return true;
    }
    Board(choices);
    return false;
}


