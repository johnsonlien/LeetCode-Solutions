#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;

    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL; 
    } 

    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }

    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight; 
    }
};

Node* construct(vector<vector<int>>& grid) {
    int n = grid.size();

    bool isLeaf = true; 
    int cell = grid[0][0];
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(cell != grid[i][j]) {
                isLeaf = false;
                break; 
            }
        }
    }

    if(isLeaf) {
        bool v;
        if(cell == 1) v = true;
        else v = false; 
        return new Node(v, true);
    }
    else {
        int sz = n/2;

        vector<vector<int>> one(sz, vector<int>(sz));
        vector<vector<int>> two(sz, vector<int>(sz));
        vector<vector<int>> three(sz, vector<int>(sz));
        vector<vector<int>> four(sz, vector<int>(sz));

        // top-left of grid
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                one[i][j] = grid[i][j];
            }
        }

        // top-right of grid;
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                two[i][j] = grid[i][j+sz];
            }
        }
        
        // bottom-left of grid
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                three[i][j] = grid[i+sz][j];
            }
        }

        // bottom-right of grid
        for(int i = 0; i < sz; i++) {
            for(int j = 0; j < sz; j++) {
                four[i][j] = grid[i+sz][j+sz];
            }
        }        

        return new Node(false, false, construct(one), construct(two), construct(three), construct(four));
    }
}

int main()
{

    vector<vector<int>> input = {{0,1}, {1,0}};
    Node* quad = construct(input);
    return 0;
}