#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Sudoku{
    public:
    string Sudoku_board[9][9];
    void create_sudoku_board();
    void display_sudoku_board();
    bool space_checker(string Sudoku_board[9][9]);
    int random_num_generator(int n);
    string choose_number(int num);
    void place_on_board(string Sudoku_board[9][9]);
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

bool Sudoku::space_checker(string Sudoku_board[9][9]){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            if(Sudoku_board[i][j]=="⬜️"){
                return true;
            }
            else return false;
        }
    }
}

int Sudoku::random_num_generator(int n){
    int temp;
    temp = rand() % n + 1;
    return temp;
}

string Sudoku::choose_number(int num){
    switch(num){
        case 1: return "1️⃣ ";
                break;
        case 2: return "2️⃣ ";
                break;
        case 3: return "3️⃣ ";
                break;
        case 4: return "4️⃣ ";
                break;
        case 5: return "5️⃣ ";
                break;
        case 6: return "6️⃣ ";
                break;
        case 7: return "7️⃣ ";
                break;
        case 8: return "8️⃣ ";
                break;
        case 9: return "9️⃣ ";
                break;        
    }
}

void Sudoku::place_on_board(string Sudoku_board[9][9]){
    srand (time(NULL));
    string temp;
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            int num = random_num_generator(9);
            temp = choose_number(num);
            Sudoku_board[i][j] = temp;
        }
    }
}

int main(){
    Sudoku S1;
    system("clear");
    S1.create_sudoku_board();
    S1.display_sudoku_board();
    cout<<endl;
    cout<<endl;
    S1.place_on_board(S1.Sudoku_board);
    S1.display_sudoku_board();
    return 0;
}


/*
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

*/