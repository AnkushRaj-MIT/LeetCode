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
    void recoverTree(TreeNode* root) {
        TreeNode *prev = NULL;
        TreeNode *first = NULL;
        TreeNode *second = NULL;
        while (root != NULL) {
            if (root->left == NULL) {
                if (prev && root->val < prev->val) {
                    if (first == NULL) first = prev;
                    second = root;
                }
                prev = root;
                root = root->right;
            }
            else {
                TreeNode *IP = root->left;
                while (IP->right != NULL && IP->right != root) IP = IP->right;
                if (IP->right == NULL) {
                    IP->right = root;
                    root = root->left;
                }
                else {
                    IP->right = NULL;
                    if (prev && root->val < prev->val) {
                        if (first == NULL) first = prev;
                        second = root;
                    }
                    prev = root;
                    root = root->right;
                }
            }
        }
        swap(first->val, second->val);
    }
};