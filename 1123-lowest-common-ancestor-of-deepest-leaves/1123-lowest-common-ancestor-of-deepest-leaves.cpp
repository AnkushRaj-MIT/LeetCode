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
    int depth(TreeNode* root){
        if(root==NULL) return 0;
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        return 1+max(leftDepth,rightDepth);
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        if(root==NULL) return NULL;
        int leftDepth=depth(root->left);
        int rightDepth=depth(root->right);
        if(leftDepth==rightDepth) return root;
        else if(leftDepth>rightDepth) return lcaDeepestLeaves(root->left);
        else return lcaDeepestLeaves(root->right);
    }
};