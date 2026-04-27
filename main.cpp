#include <iostream>
using namespace std;

class Tictactoe{
    private:
    char board[3][3];
    char player;

    public:
    Tictactoe(){
        player = 'X';
        numberBoard();
    }

    void numberBoard(){
        char n='1';
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                board[i][j]= n++ ;
            }
        }
    }

    void displayBoard(){
        for(int i=0; i<3; i++){
            cout<<"|";
            for(int j=0; j<3; j++){
                cout<<board[i][j]<<"|";
            }
            cout<<endl;
        }
    }

    char getplayer(){
        return player ;
    }

    void changePlayer(){
        player = (player == 'X') ? 'O' : 'X';
    }

    void write(int choose) {
        int row = (choose - 1) / 3;
        int col = (choose - 1) % 3;

        /* Example: choose = 7
           row= (7-1)/3= 2 (second line)
           col= (7-1)%3= 0 (zero column)
        */

        if(board[row][col]!='X' && board[row][col]!='O'){
            board[row][col]= player;
            changePlayer();
        }else{
            cout<<"This cell is full. Please try again!\n";
        }
    }

    bool checkWin() {
        for (int i = 0; i < 3; i++) {   // Horizontal control
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) 
            return true;
    }

    for (int i = 0; i < 3; i++) {     // Vertical control
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) 
            return true;
    }

    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true; // Cross control
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true; 

    return false;
    }
};

int main(){
    Tictactoe game;
    int choose;
    int counter= 0;

    while(counter<9){
        game.displayBoard();
        cout<<"Player "<<game.getplayer()<<" Enter your number(1-9): ";
        cin>>choose;

        if(choose< 1 || choose> 9){
            cout<<"Invalid. Please try again!";
            continue;
        }

        game.write(choose);
        counter++;

        if(game.checkWin()){
            game.displayBoard();
            cout<<"You won!"<<endl;
            break;
        }

        if(counter==9){
            game.displayBoard();
            cout<<"Draw, game over";
            break;
        }
    }

    return 0;
}