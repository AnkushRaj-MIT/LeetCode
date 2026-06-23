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
    int dfs(TreeNode* root){
        if(root==NULL) return 0;
        int leftLen=dfs(root->left);
        int rightLen=dfs(root->right);
        int leftPath=0,rightPath=0;
        if(root->left!=NULL && root->left->val==root->val) leftPath=leftLen+1;
        if(root->right!=NULL && root->right->val==root->val) rightPath=rightLen+1;
        ans=max(ans,leftPath+rightPath);
        return max(leftPath,rightPath);
    }

    int longestUnivaluePath(TreeNode* root) {
        dfs(root);
        return ans;
    }
};