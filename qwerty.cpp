#include<iostream>
#include<string>

using namespace std;

char Sudoku_board[9][9] = {{'5','3','.','.','7','.','.','.','.'},
                            {'6','.','.','1','9','5','.','.','.'},
                            {'.','9','8','.','.','.','.','6','.'},
                            {'8','.','.','.','6','.','.','.','3'},
                            {'4','.','.','8','.','3','.','.','1'},
                            {'7','.','.','.','2','.','.','.','6'},
                            {'.','6','.','.','.','.','2','8','.'},
                            {'.','.','.','4','1','9','.','.','5'},
                            {'.','.','.','.','8','.','.','7','9'}};



void display_sudoku_board(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout<<Sudoku_board[i][j];
        }
        cout<<endl;
    }
}


bool Sudoku_condition(int row, int col, int num){
    int r1 = sizeof(Sudoku_board[0])/sizeof(Sudoku_board[0][0]);
    int c1 = sizeof(Sudoku_board[0])/sizeof(char);
    int size = r1*c1;
    for(int i=0; i<size; i++){
        if(Sudoku_board[i][col]==(char)(num+'0')){
            return false;
        }
    }
    for(int j=0; j<size; j++){
        if(Sudoku_board[row][j]==char(num+'0')){
            return false;
        }
    }
    int sr=3*(row/3);
    int sc=3*(col/3);
    for(int i=sr; i<sr+3; i++){
        for(int j=sc; j<sc+3; j++){
            if(Sudoku_board[i][j]==(char)(num+'0')){
                return false;
            }
        }
    }
    return true;
}

bool backtraking(int row, int col){
    int r1 = sizeof(Sudoku_board[0])/sizeof(Sudoku_board[0][0]);
    int c1 = sizeof(Sudoku_board[0])/sizeof(char);
    int size = r1*c1;
    if(row==size){
        return true;
    }
    int nrow =0;
    int ncol =0;
    if(col==size-1){
        nrow=row+1;
        ncol=0;
    }
    else{
        nrow=row;
        ncol=col+1;
    }
    if(Sudoku_board[row][col]!='.'){
        if(backtraking(nrow,ncol)){
            return true;
        }
    }
        else{
            for(int i=1;i<=9;i++){
                if(Sudoku_condition(row, col, i)){
                    Sudoku_board[row][col] = (char)(i+'0');
                    if(backtraking(nrow, ncol)){
                        return true;
                    }
                    else 
                        Sudoku_board[row][col] = '.';
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

void Sudoku_Solver(){
    //display_sudoku_board(sudoku_saver);
    //Sudo=sudoku_saver;
    backtraking(0, 0);
    //display_sudoku_board(sudoku_saver);
}


int main(){
    display_sudoku_board();
    Sudoku_Solver();
    return 0;
}