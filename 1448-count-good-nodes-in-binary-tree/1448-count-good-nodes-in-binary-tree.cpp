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
    int ans=0;
    void dfs(TreeNode* root,int maxm){
        if(root==NULL) return;
        if(root->val>=maxm){
            ans++;
        }
        maxm=max(maxm,root->val);
        dfs(root->left,maxm);
        dfs(root->right,maxm);
    }
    int goodNodes(TreeNode* root) {
        int maxm=INT_MIN;
        dfs(root,maxm);
        return ans;
    }
};