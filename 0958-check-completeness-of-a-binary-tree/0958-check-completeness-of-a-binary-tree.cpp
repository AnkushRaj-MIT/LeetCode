/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int countNodes(TreeNode* root){
        if (root == NULL) return 0;
        return 1 + countNodes(root ->left) + countNodes(root -> right);
    }
    bool solve(TreeNode* root, int index, int n){
        if (root == NULL)  return true;
        if (index >= n)  return false;
        bool left = solve(root -> left, index*2 + 1, n);
        bool right = solve(root -> right, index*2 + 2, n);
        return (left && right);
    }
    bool isCompleteTree(TreeNode* root){
        int index = 0;
        int n = countNodes(root);
        return solve (root, index, n);
    }
};