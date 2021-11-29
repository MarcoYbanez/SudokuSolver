#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class sudoku {
    private:
        int size; // number of rows Ex. 16
        int sizePerBox; // number inside a box Ex. 4
        bool checkRow(); //check if a number is valid in a row
        bool checkColumn(); //check if a number is valid in a column
        bool checkBox(); //check if a number is valid in a box
        vector<vector<int> > board;  // holds the sudoku
        int curRow;
        int curCol;
    public:
        sudoku(int N);
        bool dfsVisit(int row, int column);
        void printBoard();
        bool checkMissing();
};


bool sudoku::checkRow(int newNum, int row_ind){

  for(auto i = board[row_ind].begin(); i != board[row_ind].end(); ++i){
    if(*i == newNum){
      return false;
    }
    
  }

  return true;
}

bool sudoku::checkColumn(int newNum, int col_ind){

  for(auto i = board[col_ind].begin(); i != board[col_ind].end(); ++i){
    if(*i == newNum){
      return false;
    }
  }
  return true;

}

sudoku::sudoku(int N)
:size(N * N), sizePerBox(N), curRow(0), curCol(0) {
    board.resize(size);
    int tempInt;
    for(int i = 0 ; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cin >> tempInt;
            board[i].push_back(tempInt);
        }
    }
}

void sudoku::printBoard() {
    cout << "------------------------------------------" << endl;
    for(int i = 0 ; i < size; i++) {
        cout << "|";
        for(int j = 0; j < size; j++) {
            cout << board[i][j] << " ";
            if(j % sizePerBox - 3 == 0) {
                cout << "|";
            }
        }
        if(i % sizePerBox - 3 == 0) {
            cout << endl;
            cout << "------------------------------------------";
        }
        cout << endl;
    }
}

bool sudoku::checkBox(int curX, int curY, int newNum) {
    int startX;
    int endX;
    int startY;
    int endY;
    if(curX < 4) {
       startX = 0;
       endX = 3;
    } else if(curX >= 4 && curX < 8) {
        startX = 4;
        endX = 7;
    } else if(curX >= 8 && curX < 12) {
        startX = 8;
        endX = 11;
    } else {
        startX = 12;
        endX = 15;
    }
    if(curY < 4) {
       startX = 0;
       endX = 3;
    } else if(curY >= 4 && curY < 8) {
        startX = 4;
        endX = 7;
    } else if(curY >= 8 && curY < 12) {
        startX = 8;
        endX = 11;
    } else {
        startX = 12;
        endX = 15;
    }
    for(int i = startX; i < endX; i++) {
        for(int j = startY; j < endY; j++) {
            if (board[i][j] == newNum) {
                return false;
            }
        }
    }
    return true;
}

bool sudoku::checkMissing() {
    for(int i = 0; i < 16; i++) {
        for(int j = 0; j < 16; j++) {
            if(board[i][j] == 0) {
                curRow = i;
                curCol = j;
                return false;
            }
        }
    }
    return true;
}

int main() {
    int N;
    cin >> N;
    sudoku mySudoku(N);
    // if(!mySudoku.dfsVisit(0,0)) {
    //     cout << "There is not a valid solution." << endl;
    // } else {
    //     mySudoku.printBoard();
    // }
    mySudoku.printBoard();
    return 0;
}
