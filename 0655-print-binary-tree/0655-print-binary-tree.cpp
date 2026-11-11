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
    int height(TreeNode* root) {
        if (root == NULL) return -1;
        int leftH = height(root->left);
        int rightH = height(root->right);
        return 1 + max(leftH, rightH);
    }
    void solve(TreeNode* root, int row, int col, int h,vector<vector<string>>& ans) {
        if (root == NULL) return;
        ans[row][col] = to_string(root->val);
        if(row==h) return;
        int offset = 1 << (h - row - 1);
        if (root->left) {
            solve(root->left, row + 1, col - offset, h, ans);
        }
        if (root->right) {
            solve(root->right, row + 1, col + offset, h, ans);
        }
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int h = height(root);
        int rows = h + 1;
        int cols = (1 << (h + 1)) - 1;
        vector<vector<string>> ans(rows, vector<string>(cols, ""));
        solve(root, 0, (cols - 1) / 2, h, ans);
        return ans;
    }
};