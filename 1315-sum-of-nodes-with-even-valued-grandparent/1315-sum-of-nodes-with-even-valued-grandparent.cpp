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
    int sum=0;
    void dfs(TreeNode* root,TreeNode* grandParent,TreeNode* parent){
        if(root==NULL) return;
        if(grandParent!=NULL && grandParent->val%2==0) sum+=root->val;
        dfs(root->left,parent,root);
        dfs(root->right,parent,root);
    }
    int sumEvenGrandparent(TreeNode* root) {
        TreeNode* parent=NULL;
        TreeNode* grandParent=NULL;
        dfs(root,grandParent,parent);
        return sum;
    }
};