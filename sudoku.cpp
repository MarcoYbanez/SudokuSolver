#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <math.h>
using namespace std;

class sudoku {
    private:
        int size; // number of rows Ex. 16
        int sizePerBox; // number inside a box Ex. 4
        bool checkRow(int, int); //check if a number is valid in a row
        bool checkColumn(int, int); //check if a number is valid in a column
        bool checkBox(int, int, int); //check if a number is valid in a box
        vector<vector<int> > board;  // holds the sudoku
    public:
        sudoku(int N);
        void out_results();
        void dfs();
        bool dfsVisit();
        void printBoard();
        bool checkMissing(int&, int&);
};

void sudoku::dfs(){

  if(!dfsVisit()){
    cout << "No Solution\n";
  }
  else{
      cout << "Solved\n";
  }


}


bool sudoku::dfsVisit(){
  
  vector<int> domain{1, 2, 3, 4,
                     5, 6, 7, 8,
                     9, 10, 11, 12, 
                     13, 14, 15, 16
  };
  int curCol, curRow;

  //checkMissing(curCol, curRow);
  //cerr << "curRow: " << curRow << std::endl;
  //cerr << "curCol: " << curCol<< std::endl;

  if(!checkMissing(curRow, curCol)){
    int i;
    for(i = 0 ; i < (int)domain.size(); ++i){
      if(checkRow(curRow, domain[i]) && checkColumn(curCol, domain[i]) && checkBox(curRow, curCol,domain[i])){
        board[curRow][curCol] = domain[i];
        
        if(dfsVisit()){
          return true;
        }
        
      }
    }

    if(i >= 16){
      board[curRow][curCol] = 0;
      return false;
    }
  }
  return true;
}

bool sudoku::checkRow(int curRow, int newNum){

  for(auto i = board[curRow].begin(); i != board[curRow].end(); ++i){
    if(*i == newNum){
      return false;
    }
    
  }

  return true;
}

bool sudoku::checkColumn(int curCol, int newNum){

  for(auto i = 0; i < 16; ++i){
    if(board[i][curCol] == newNum){
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
       startY = 0;
       endY = 3;
    } else if(curY >= 4 && curY < 8) {
        startY = 4;
        endY = 7;
    } else if(curY >= 8 && curY < 12) {
        startY = 8;
        endY = 11;
    } else {
        startY = 12;
        endY = 15;
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

bool sudoku::checkMissing(int& curRow, int& curCol) {
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
void sudoku::out_results(){

  ofstream out("results.txt");
  
  //out << size << std::endl;
  for(int i = 0; i < size; ++i){
    for(int j =0; j < size; ++j){
      out << board[i][j] << " ";
    }
    out << endl;
  }
  out.close();
}

int main() {
    int N;
    cin >> N;
    sudoku mySudoku(N);
    mySudoku.printBoard();

    mySudoku.dfs();

    mySudoku.printBoard();
    mySudoku.out_results();



    return 0;
}
