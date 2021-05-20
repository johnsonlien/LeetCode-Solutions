#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    if (nums.size() == 0)
        return NULL;
    // Find the maximum value
    int maxValue = nums[0];
    int maxIndex = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > maxValue)
        {
            maxValue = nums[i];
            maxIndex = i;
        }
    }

    // Get the left and right sections of the nums vector
    vector<int> left(nums.begin(), nums.begin() + maxIndex);
    vector<int> right(nums.begin() + maxIndex + 1, nums.end());

    TreeNode *root = new TreeNode(maxValue);
    root->left = constructMaximumBinaryTree(left);
    root->right = constructMaximumBinaryTree(right);

    return root;
}

int main()
{
    vector<vector<int>> inputs = {{3, 2, 1, 6, 0, 5}, {3, 2, 1}};
    for (int i = 0; i < inputs.size(); i++)
    {
        constructMaximumBinaryTree(inputs[i]);
    }
}