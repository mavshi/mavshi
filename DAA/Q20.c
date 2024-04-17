//Q20 Write a program in C/C++/ Java to solve 4 Queens Problem using Backtracking
//Sol
#include <iostream>
#include <vector>
using namespace std;
bool isSafe(vector<vector<int>> &board, int row, int col) {
  for (int i = 0; i < col; i++)
    if (board[row][i])
      return false;
  for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    if (board[i][j])
      return false;
  for (int i = row, j = col; i < 4 && j >= 0; i++, j--)
    if (board[i][j])
      return false;
  return true;
}
bool solveNQueens(vector<vector<int>> &board, int col) {
  if (col >= 4)
    return true;
  
  for (int i = 0; i < 4; i++) {
    if (isSafe(board, i, col)) {
      board[i][col] = 1;
      if (solveNQueens(board, col + 1))
        return true;
      board[i][col] = 0;
    }
  }
  return false;
}
void printSolution(vector<vector<int>> &board) {
  for (int i = 0; i < 4; i++) {
    for (int j = 0; j < 4; j++) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
}
int main() {
  vector<vector<int>> board(4, vector<int>(4, 0));
  if (solveNQueens(board, 0) == false) {
    cout << "Solution does not exist" << endl;
  } else {
    cout << "Solution:" << endl;
    printSolution(board);
  }
  return 0;
}
