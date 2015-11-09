#include "util.hpp"

class Solution {
private:
    vector<vector<bool>> row, col, block;
    bool dfs(int i, int j, vector<vector<char>>& board) {
        int x, y;
        if (j < 8) {
            x = i;
            y = j+1;
        } else {
            x = i+1;
            y = 0;
        }
        if (board[i][j] == '.') {
            for (int d = 0; d < 9; d++) {
                if (!row[i][d] && !col[j][d] && !block[i/3*3 + j/3][d]) {
                    row[i][d] = true;
                    col[j][d] = true;
                    block[i/3*3 + j/3][d] = true;
                    board[i][j] = '0'+d+1;
                    if (x == 9)
                        return true;
                    if (dfs(x, y, board))
                        return true;
                    row[i][d] = false;
                    col[j][d] = false;
                    block[i/3*3 + j/3][d] = false;
                    board[i][j] = '.';
                }
            }
            return false;
        } else {
            if (x == 9)
                return true;
            else
                return dfs(x, y, board);
        }
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        row.assign(9, vector<bool>(9, false));
        col.assign(9, vector<bool>(9, false));
        block.assign(9, vector<bool>(9, false));
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int d = board[i][j] - '0' - 1;
                    row[i][d] = true;
                    col[j][d] = true;
                    block[i/3*3 + j/3][d] = true;
                }
        if (dfs(0, 0, board))
            cout << "success" << endl;
        else
            cout << "fail" << endl;
    }
};
