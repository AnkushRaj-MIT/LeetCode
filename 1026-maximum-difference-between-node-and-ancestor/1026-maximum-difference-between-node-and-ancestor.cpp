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
    int val=0;
    void dfs(TreeNode* root,int maxm,int minm){
        if(root==NULL) return;
        maxm=max(root->val,maxm);
        minm=min(root->val,minm);
        val=max(val,maxm-minm);
        dfs(root->left,maxm,minm);
        dfs(root->right,maxm,minm);
    }
    int maxAncestorDiff(TreeNode* root) {
        int maxm=INT_MIN;
        int minm=INT_MAX;
        dfs(root,maxm,minm);
        return val;
    }
};