#include <iostream>
#include <vector>
#include <string>

using namespace std;
int getLiveNeighbors(const vector<vector<int>>& board, int row, int col) {
        //   |_|_|_|
        //   |_|x|_|
        //   |_|_|_|
        int n = board.size();
        int m = board[0].size();
        const int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        const int y[8] = {1, 1, 0, -1, -1, -1, 0, 1};
        
        int numNeighbors = 0;
        for(int i = 0; i < 8; i++) {
            if(row + x[i] < n && row + x[i] >= 0 && col + y[i] < m && col + y[i] >= 0) {
                numNeighbors += board[row+x[i]][col+y[i]];
            }
        }
        return numNeighbors;
        
    }
void gameOfLife(vector<vector<int>>& board) {
        // In order to apply the rules of life simultaneously to each cell,
        // we want to iterate through the board and keep track of what will happen
        // to each cell.
        // Then, after we finish iterating through the board will we 
        // make the changes to get the next board configuration. 
        
        vector<vector<int>> live2die;   // Stores coordinates of live cells that will die
        vector<vector<int>> die2live;   // Store coordinates of dead cells to revive
        
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                int cell = board[i][j];
                int numNeighbors = getLiveNeighbors(board, i, j);
                if(cell == 1) { 
                    if(numNeighbors < 2 || numNeighbors > 3) {
                        live2die.push_back({i, j});    // Rules 1 and 3
                    }
                }
                else {
                    // Rule 4
                    if(numNeighbors == 3) die2live.push_back({i, j});
                }
            }
        }
        
        // Kill the live cells
        for(int i = 0; i < live2die.size(); i++) {
            board[live2die[i][0]][live2die[i][1]] = 0;
        }
        
        // Revive the dead cells
        for(int i = 0; i < die2live.size(); i++) {
            board[die2live[i][0]][die2live[i][1]] = 1; 
        }
        
    }

int main()
{
    vector<vector<int>> board = {{0,1,0}, {0,0,1},{1,1,1},{0,0,0}};
    gameOfLife(board);
    return 0;
}