#include <iostream>
#include <bits/stdc++.h>

using namespace std;


bool canplace(int row, int col, vector<vector<char>>& board, char c) {
    for (int i = 0; i < 9; i++) {
        if (board[i][col] == c) return false;
        if (board[row][i] == c) return false;
        if (board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == c) return false;
    }
    return true;
}
bool solve(int starti, int startj, vector<vector<char>>& board) {
    for (int i = starti; i < board.size(); i++) {
        for (int j = startj; j < board[0].size(); j++) {
            if (board[i][j] == '.') {
                for (char c = '1'; c <= '9'; c++) {
                    if (canplace(i, j, board, c)) {
                        board[i][j] = c;
                        if (solve(i, j, board))
                            return true;
                        else
                            board[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void solveSudoku(vector<vector<char>>& board) {
    cout << solve(0, 0, board) << endl;
}

void printarr(vector<vector<char>>& board) {
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++)
        {
            cout << board[i][j] << ' ';
        }
        cout << endl;
    } cout << endl;
}

int main() {
    vector<vector<char>> board = { {'5','3','.','.','7','.','.','.','.'},{'6','.','.','1','9','5','.','.','.'},{'.','9','8','.','.','.','.','6','.'},{'8','.','.','.','6','.','.','.','3'},{'4','.','.','8','.','3','.','.','1'},{'7','.','.','.','2','.','.','.','6'},{'.','6','.','.','.','.','2','8','.'},{'.','.','.','4','1','9','.','.','5'},{'.','.','.','.','8','.','.','7','9'} };
    solveSudoku(board);
    printarr(board);

    return 0;
}