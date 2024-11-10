#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <time.h>

char board[3][3];
const char PLAYER = '0';
const char COMPUTER = 'X';

void reset_Board();
void print_Board();
int check_free_spaces();
void player_move();
void computer_move();
char check_winner();
void print_winner(char);


int main(void){

    char winner = ' ';
    reset_Board();

    while(winner == ' ' && check_free_spaces() != 0){

        print_Board();

        player_move();
        winner = check_winner();
        if (winner != ' '|| check_free_spaces() ==0 ){
            break;
        }

        computer_move();
        winner = check_winner();
        if (winner != ' ' || check_free_spaces() ==0 ){
            break;
        }
          

    }
    print_Board();
    print_winner(winner);



    return 0;
}

void reset_Board(){
    for(int i = 0; i<3;i++){


        for(int j = 0;j<3;j++){
            board[i][j] = ' ';
        }
    }

}

void print_Board(){

    printf("%c  | %c | %c", board[0][0],board[0][1],board[0][2]);
    printf("\n---|---|---\n");

    printf("%c  | %c | %c", board[1][0],board[1][1],board[1][2]);
    printf("\n---|---|---\n");

    printf("%c  | %c | %c", board[2][0],board[2][1],board[2][2]);
    printf("\n");
}
int check_free_spaces(){
    int Freespaces = 9;

    for(int i =0 ; i<3;i++){

            for(int j =0 ; j<3;j++){
                if (board[i][j]!=' ')
                  Freespaces--;
    }

    }

    return Freespaces;

}
void player_move(){

    int x;
    int y;

    do{
    printf("Enter row (1-3): ");
    scanf("%d",&x);
    x--;


    printf("Enter column (1-3): ");
    scanf("%d",&y);
    y--;

    if (board[x][y]!=' '){

        printf("Invalid move \n");
    }
    else
      board[x][y] = PLAYER;
      break;


    }while (board[x][y]!=' ');

}

void computer_move(){

    srand(time(0));
    int x;
    int y;
    if(check_free_spaces>0){
        do
        {
            x = rand()%3;
            y = rand()%3;
        } while (board[x][y]!=' ');

        board[x][y] = COMPUTER;     
    }
    else 
      print_winner(' ');

}

char check_winner(){

    //check rows 
    for(int i =0;i<3;i++){

        if(board[i][0]==board[i][1]==board[i][2])
          return board[i][0];
    }

    //check columns 
    for(int i =0;i<3;i++){

    if(board[0][i]==board[1][i]==board[2][i])
      return board[0][i];
    }


    //check diagnols 

    if(board[0][0]==board[1][1]==board[2][2])
       return board[0][0];

    if(board[2][0]==board[1][1]==board[0][2])
      return board[0][0];

    return ' ';

}
void print_winner(char Winner){
    if (Winner ==COMPUTER)
      printf("Computer wins.\n");

    else if(Winner == PLAYER)
      printf("You win!");

    else  
      printf("It is a draw!");  

}
