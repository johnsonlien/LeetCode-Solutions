#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool dfs(vector<vector<char>>& board, string& word, int row, int col, int pos) {
    if(pos == word.length()) return true;
    if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return false;

    if(board[row][col] == word[pos]) {
        char c = board[row][col];   // Save this character for backtracking
        board[row][col] = '#';      // Replace character so we don't use it again
        bool temp = dfs(board, word, row+1, col, pos+1) || 
        dfs(board, word, row-1, col, pos+1) || 
        dfs(board, word, row, col+1, pos+1) ||
        dfs(board, word, row, col-1, pos+1);
        board[row][col] = c;        // Replace with original character 

        return temp;
    }
    return false;
}

bool exist(vector<vector<char>>& board, string word) {
    for(int i = 0; i < board.size(); i++) {
        for(int j = 0; j < board[0].size(); j++) {
            if(dfs(board, word, i, j, 0)) return true;
        }
    }

    return false;
}

int main() {
    vector<vector<char>> board = 
    {{'A','B','C','E'},
    {'S','F','C','S'}, 
    {'A','D','E','E'}};
    string word = "ABCCED";

    bool exists = exist(board, word);

    return 0;
}