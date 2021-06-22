#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    ~TreeNode() { 
        delete this; 
    }
};

int getWidth(TreeNode* root) {
    // Function to get the width of a binary tree
    if(!root) return 0;

    int l = getWidth(root->left);
    int r = getWidth(root->right);

    return max(l, r) * 2 + 1;
}

int getHeight(TreeNode* root) {
    // Function to get the height of a binary tree
    if(!root) return 0;

    int l = getHeight(root->left);
    int r = getHeight(root->right);

    return max(l, r) + 1; 
}

void dfs(vector<vector<string>>& ans, TreeNode* node, int h, int l, int r) {
    // Recursive function to update our ans vector 
    // l is the leftmost index a node could be at and r is the rightmost index a node could be
    // h is the current height of the node

    if(!node) return;

    int mid = (l+r)/2; // Get the middle of where the node should be
    ans[h][mid] = to_string(node->val);

    // Recursive call to the next height
    dfs(ans, node->left, h+1, l, mid-1);
    dfs(ans, node->right, h+1, mid+1, r);
}

vector<vector<string>> printTree(TreeNode* root) {
    int w = getWidth(root);
    int h = getHeight(root);
    vector<vector<string>> ans(h, vector<string>(w, ""));

    dfs(ans, root, 0, 0, w-1);

    return ans; 
}

void printVector(const vector<vector<string>>& v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = 0; j < v[i].size(); j++) {
            cout << v[i][j];
            if(j + 1 < v[i].size()) cout << ",";
        }
        cout << "\n";
    }
}

int main()
{
    TreeNode * root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);

    vector<vector<string>> arr = printTree(root);
    printVector(arr);
    return 0;
}