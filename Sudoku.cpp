#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<string>

using namespace std;

string Sudoku_board[9][9] = {{"5","3",".",".","7",".",".",".","."},
                            {"6",".",".","1","9","5",".",".","."},
                            {".","9","8",".",".",".",".","6","."},
                            {"8",".",".",".","6",".",".",".","3"},
                            {"4",".",".","8",".","3",".",".","1"},
                            {"7",".",".",".","2",".",".",".","6"},
                            {".","6",".",".",".",".","2","8","."},
                            {".",".",".","4","1","9",".",".","5"},
                            {".",".",".",".","8",".",".","7","9"}};


class Sudoku{
    public:
    //string Sudoku_board[9][9];
    void create_sudoku_board();
    void display_sudoku_board();
    void display_sudoku_board(string Sudoku_board[9][9]);
    bool space_checker(string Sudoku_board[9][9], int i, int j);
    int random_num_generator(int n);
    string choose_number(int num);
    void place_on_board(string Sudoku_board[9][9]);
    void place_player_num(int cell_num, string Sudoku_board[9][9], int num);
    void Sudoku_Solver(/*char Sudoku_board[9][9]*/);
    bool backtraking(/*char Sudoku_board[9][9],*/ int row, int col);
    bool Sudoku_condition(/*char Sudoku_board[9][9],*/ int row, int col, int num);
    char sudoku_saver[9][9];
};

void Sudoku::create_sudoku_board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            Sudoku_board[i][j] = '.';
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

bool Sudoku::Sudoku_condition(/*char Sudoku_board[9][9],*/ int row, int col, int num){
    int r1 = sizeof(Sudoku_board[0])/sizeof(Sudoku_board[0][0]);
    int c1 = sizeof(Sudoku_board[0])/sizeof(string);
    for(int i=0; i<r1-1; i++){
        if(Sudoku_board[row][i]==to_string(num)){
            return false;
        }
    }
    for(int j=0; j<c1-1; j++){
        if(Sudoku_board[j][col]==to_string(num)){
            return false;
        }
    }
    int sr=3*(row/3);
    int sc=3*(col/3);
    for(int i=sr; i<sr+3; i++){
        for(int j=sc; j<sc+3; j++){
            if(Sudoku_board[i][j]==to_string(num)){
                return false;
            }
        }
    }
    return true;
}

bool Sudoku:: backtraking(/*char Sudoku_board[9][9],*/ int row, int col){
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
    if(Sudoku_board[row][col]!="."){
        if(backtraking(/*Sudoku_board,*/nrow,ncol)){
            return true;
        }
    }
        else{
            for(int i=1;i<=9;i++){
                if(Sudoku_condition(/*Sudoku_board,*/ row, col, i)){
                    Sudoku_board[row][col] = to_string(i);
                    if(backtraking(/*Sudoku_board,*/ nrow, ncol))
                        return true;
                    else 
                        Sudoku_board[row][col] = ".";
                }
            }
        }
        //for(int i=0; i<9; i++){
        //    for(int j=0; j<9; j++){
        //        Sudoku_board[i][j]=sudoku_saver[i][j];
         //   }
        //}
    return false;
}

void Sudoku::Sudoku_Solver(/*char Sudo[9][9]*/){
    //display_sudoku_board(sudoku_saver);
    //Sudo=sudoku_saver;
    backtraking(/*Sudo,*/ 0, 0);
    //display_sudoku_board(sudoku_saver);
}


int main(){
    //Sudoku S1;
    Sudoku S4;
    int choice;
    system("clear");
    cout<<endl<<"1. To solve a generated SUDOKU puzzle";
    cout<<endl<<"2. Enter a puzzle to get solution";
    cout<<"\nPlease select your choice: ";
    //cin>>choice;
    choice=2;
    switch(choice){
        case 1: 
                break;

        case 2: /*int cell_num, digits, num;
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
                S4.display_sudoku_board(S4.Sudoku_board);
                S4.Sudoku_Solver(S4.Sudoku_board);
                S4.display_sudoku_board(S4.Sudoku_board);*/
                cout<<endl;
                S4.display_sudoku_board(Sudoku_board);
                //cout<<endl<<sizeof(sudokuboard);
                S4.Sudoku_Solver();
                S4.display_sudoku_board(Sudoku_board);
                //sudokuboard=sudoku_saver
                //S4.display_sudoku_board(sudoku_saver);
                //S4.display_sudoku_board(sudoku_saver);
                //S4.display_sudoku_board(sudokuboard);
                break;

        default: cout<<"You have selected wrong option :(";
    }
}
    /*S1.create_sudoku_board();
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
    return 0;
}
=======

*/










/*class Solution {
   public boolean isSafe(char[][] board, int row, int col, int number) {
       //column
       for(int i=0; i<board.length; i++) {
           if(board[i][col] == (char)(number+'0')) {
               return false;
           }
       }
      
       //row
       for(int j=0; j<board.length; j++) {
           if(board[row][j] == (char)(number+'0')) {
               return false;
           }
       }
      
       //grid
       int sr = 3 * (row/3);
       int sc = 3 * (col/3);
      
       for(int i=sr; i<sr+3; i++) {
           for(int j=sc; j<sc+3; j++) {
               if(board[i][j] == (char)(number+'0')) {
                   return false;
               }
           }
       }
return true;
   }
  
   public boolean helper(char[][] board, int row, int col) {
       if(row == board.length) {
           return true;
       }
      
       int nrow = 0;
       int ncol = 0;
      
       if(col == board.length-1) {
           nrow = row + 1;
           ncol = 0;
       } else {
           nrow = row;
           ncol = col + 1;
       }
      
       if(board[row][col] != '.') {
           if(helper(board, nrow, ncol)) {
               return true;
           }
       } else {
          
           //fill the place
           for(int i=1; i<=9; i++) {
               if(isSafe(board, row, col, i)) {
                   board[row][col] = (char)(i+'0');
                   if(helper(board, nrow, ncol))
                       return true;
                   else
                        board[row][col] = '.';
               }
           }
       }
                     
       return false;
   }
  
   public void solveSudoku(char[][] board) {
       helper(board, 0, 0);
   }
}
*/