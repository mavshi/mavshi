//Q21 Write a program in C/C++/ Java to show board configuration of 4 queens problem
//Sol
#include <iostream>
#include <vector>
using namespace std;
void printBoard(const vector<int>& board) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}
int main() {
    vector<int> board(4);
    cout << "All possible board configurations for 4 Queens problem:" << endl;
    int count = 0;
    for (int i1 = 0; i1 < 4; i1++) {
        for (int i2 = 0; i2 < 4; i2++) {
            for (int i3 = 0; i3 < 4; i3++) {
                for (int i4 = 0; i4 < 4; i4++) {
                    if (i1 != i2 && i1 != i3 && i1 != i4 &&
                        i2 != i3 && i2 != i4 &&
                        i3 != i4) {
                        board[0] = i1;
                        board[1] = i2;
                        board[2] = i3;
                        board[3] = i4;
                        cout << "Board configuration " << ++count << ":" << endl;
                        printBoard(board);
                    }
                }
            }
        }
    }
    return 0;
}
