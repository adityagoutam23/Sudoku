#include<iostream>

using namespace std;

class Sudoku{
    public:
    string Sudoku_board[9][9];
    void create_sudoku_board();
    void display_sudoku_board();
};

void Sudoku::create_sudoku_board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            Sudoku_board[i][j] = "⬜️";
        }
    }
}

void Sudoku::display_sudoku_board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<Sudoku_board[i][j];
        }
        cout<<endl;
    }
}

int main(){
    Sudoku S1;
    Sudoku S2;
    S1.create_sudoku_board();
    S1.display_sudoku_board();
    cout<<endl;
    cout<<endl;
    S2.create_sudoku_board();
    S2.display_sudoku_board();
    cout<<endl;
    cout<<endl;
    S1.Sudoku_board[0][4]="1️⃣ ";
    S1.Sudoku_board[0][3]="9️⃣ ";
    S1.display_sudoku_board();
    cout<<endl;
    cout<<endl;
    cout<<endl;
    S2.Sudoku_board[5][7]="7️⃣ ";
    S2.display_sudoku_board();
    cout<<endl;
    return 0;
}