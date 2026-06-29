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
    int curr=0;
    void solver(TreeNode* root,int k){
        if(root==NULL) return;
        solver(root->left,k);
        curr++;
        if(curr==k) ans=root->val;
        solver(root->right,k);
    }
    int kthSmallest(TreeNode* root,int k) {
        solver(root,k);
        return ans;
    }
};