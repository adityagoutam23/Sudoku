#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>

using namespace std;


class Sudoku{
    public:
    void create_sudoku_board();
    void display_sudoku_board(string Sudoku_board[9][9]);
    bool space_checker(string Sudoku_board[9][9], int i, int j);
    int random_num_generator(int n);
    string choose_number(int num);
    void place_on_board(string Sudoku_board[9][9]);
    void place_player_num(int cell_num, string Sudoku_board[9][9], int num);
    void Sudoku_Solver();
    bool backtraking(int row, int col);
    bool Sudoku_condition(int row, int col, int num);
    void Sudoku_generator(string Sudoku_board[9][9]);
    int random_place_generator(int n);
    void seperator(string Sudoku_board[9][9]);
    string Sudoku_board[9][9];
    string Sudoku_board_hints[9][9];
    string Sudoku_board_player[9][9];
};

void Sudoku::create_sudoku_board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            Sudoku_board[i][j] = "⬜️";
            Sudoku_board_hints[i][j] = "⬜️";
            Sudoku_board_player[i][j] = "⬜️";
        }
    }
}

void Sudoku::display_sudoku_board(string Sudoku_board[9][9]){
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

int Sudoku::random_place_generator(int n){
    int temp;
    temp = rand() % n + 0;
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


void Sudoku::place_player_num(int cell_num, string Sudoku_board[9][9], int num){
    int i , j;
    string board_num;
    i=cell_num/9;
    j=cell_num%9;
    board_num = choose_number(num);
    Sudoku_board[i][j]=board_num;
}

bool Sudoku::Sudoku_condition(int row, int col, int num){
    int r1 = sizeof(Sudoku_board[0])/sizeof(Sudoku_board[0][0]);
    int c1 = sizeof(Sudoku_board[0])/sizeof(string);
    for(int i=0; i<r1-1; i++){
        if(Sudoku_board[row][i]==choose_number(num)){
            return false;
        }
    }
    for(int j=0; j<c1-1; j++){
        if(Sudoku_board[j][col]==choose_number(num)){
            return false;
        }
    }
    int sr=3*(row/3);
    int sc=3*(col/3);
    for(int i=sr; i<sr+3; i++){
        for(int j=sc; j<sc+3; j++){
            if(Sudoku_board[i][j]==choose_number(num)){
                return false;
            }
        }
    }
    return true;
}

bool Sudoku:: backtraking(int row, int col){
    int r1 = sizeof(Sudoku_board[0])/sizeof(Sudoku_board[0][0]);
    int c1 = sizeof(Sudoku_board[0])/sizeof(string);
    if(row==r1){
        return true;
    }
    int nrow =0;
    int ncol =0;
    if(col==c1-1){
        nrow=row+1;
        ncol=0;
    }
    else{
        nrow=row;
        ncol=col+1;
    }
    if(Sudoku_board[row][col]!="⬜️"){
        if(backtraking(nrow,ncol)){
            return true;
        }
    }
        else{
            for(int i=1;i<=9;i++){
                if(Sudoku_condition(row, col, i)){
                    Sudoku_board[row][col] = choose_number(i);
                    if(backtraking(nrow, ncol))
                        return true;
                    else 
                        Sudoku_board[row][col] = "⬜️";
                }
            }
        }
    return false;
}

void Sudoku::Sudoku_Solver(){
    backtraking(0, 0);
}

void Sudoku::Sudoku_generator(string Sudoku_board[9][9]){
    srand (time(NULL));
    int random_place = random_place_generator(80);
    int random_num = random_num_generator(9);
    place_player_num(random_place, Sudoku_board, random_num);
}

void Sudoku::seperator(string Sudoku_board[9][9]){
    srand (time(NULL));
    int temp=0;
    int count=0;
    temp = rand() % 40 + 20;
    cout<<endl<<temp<<endl;
    for(int m=0; m<9; m++){
        for(int n =0; n<9; n++){
            Sudoku_board_player[m][n] = Sudoku_board[m][n];
        }
    }
    for(int k=0; k<temp; k++){
        int i=0,j=0;
        int random_place = random_place_generator(80);
        i=random_place/9;
        j=random_place%9;
        if(Sudoku_board_hints[i][j]=="⬜️"){
            Sudoku_board_hints[i][j] = Sudoku_board_player[i][j];
            Sudoku_board_player[i][j] = "⬜️";  
            count++; 
        }
        else{
            k=k-1;
            continue;
        }
    }
    cout<<endl<<count<<endl;
}


int main(){
    Sudoku S1,S4;
    int choice;
    system("clear");
    cout<<endl<<"1. To solve a generated SUDOKU";
    cout<<endl<<"2. Enter a puzzle to get solution";
    cout<<"\nPlease select your choice: ";
    cin>>choice;
    switch(choice){
        case 1: S1.create_sudoku_board();
                S1.Sudoku_generator(S1.Sudoku_board);
                S1.display_sudoku_board(S1.Sudoku_board);
                cout<<endl;
                S1.Sudoku_Solver();
                S1.display_sudoku_board(S1.Sudoku_board);
                cout<<endl;
                S1.seperator(S1.Sudoku_board);
                S1.display_sudoku_board(S1.Sudoku_board);
                cout<<endl;
                S1.display_sudoku_board(S1.Sudoku_board_player);
                cout<<endl;
                S1.display_sudoku_board(S1.Sudoku_board_hints);
                cout<<endl;
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
                cout<<endl;
                S4.display_sudoku_board(S4.Sudoku_board);
                S4.Sudoku_Solver();
                cout<<endl;
                S4.display_sudoku_board(S4.Sudoku_board);
                break;

        default: cout<<"You have selected wrong option :(";
    }
}