#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

class Sudoku{
    public:
    string Sudoku_board[9][9];
    void create_sudoku_board();
    void display_sudoku_board();
    bool space_checker(string Sudoku_board[9][9], int i, int j);
    int random_num_generator(int n);
    string choose_number(int num);
    void place_on_board(string Sudoku_board[9][9]);
    void place_player_num(int cell_num, string Sudoku_board[9][9], int num);
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

bool Sudoku::space_checker(string Sudoku_board[9][9], int i, int j){
    
            if(Sudoku_board[i][j]=="⬜️"){
                return true;
            }
            else return false;
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

void Sudoku::place_player_num(int cell_num, string Sudoku_board[9][9], int num){
    int i , j;
    string board_num;
    i=cell_num/9;
    j=cell_num%9;
    board_num = choose_number(num);
    Sudoku_board[i][j]=board_num;
}

int main(){
    Sudoku S1;
    Sudoku S4;
    int choice;
    system("clear");
    cout<<endl<<"1. To solve a generated SUDOKU puzzle";
    cout<<endl<<"2. Enter a puzzle to get solution";
    cout<<"\nPlease select your choice: ";
    cin>>choice;
    switch(choice){
        case 1: 
                break;

        case 2: int cell_num, digits, num;
                S4.create_sudoku_board();
                cout<<endl<<"How many digits do you want to enter on board: ";
                cin>>digits;
                for(int i=0; i<digits; i++){
                    cout<<endl<<"Enter cell number from 0-80 in which you want to place number: ";
                    cin>>cell_num;
                    cout<<endl<<"What number do you want to enter: ";
                    cin>>num;
                    S4.place_player_num(cell_num, S4.Sudoku_board, num);
                }
                //system("clear");
                cout<<endl;
                S4.display_sudoku_board();
                break;

        default: cout<<"You have selected wrong option :(";
    }
    /*S1.create_sudoku_board();
    S1.display_sudoku_board();
    cout<<endl;
    cout<<endl;
    S1.place_on_board(S1.Sudoku_board);
    S1.display_sudoku_board();*/
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