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
    void inorderTraversal(TreeNode* root,vector<int> &arr){
        if(root==NULL) return;
        inorderTraversal(root->left,arr);
        arr.push_back(root->val);
        inorderTraversal(root->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> arr;
        inorderTraversal(root,arr);
        int n=arr.size();
        for(int i=1;i<n;i++){
            if(arr[i]<=arr[i-1]) return false;
        }
        return true;
    }
};