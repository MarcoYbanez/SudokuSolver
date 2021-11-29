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
    public:
        sudoku(int N);
        bool dfsVisit(int row, int column);
        void printBoard();
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
:size(N * N), sizePerBox(N) {
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
