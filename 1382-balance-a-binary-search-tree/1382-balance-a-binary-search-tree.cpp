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
    TreeNode* bst(vector<int> arr,int left,int right){
        if(left>right) return NULL;
        int mid=left+(right-left)/2;
        TreeNode* root=new TreeNode(arr[mid]);
        root->left=bst(arr,left,mid-1);
        root->right=bst(arr,mid+1,right);
        return root;
    }
    void inorder(TreeNode* root,vector<int> &arr){
        if(root==NULL) return;
        inorder(root->left,arr);
        arr.push_back(root->val);
        inorder(root->right,arr);
    }
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> arr;
        inorder(root,arr);
        return bst(arr,0,arr.size()-1);
    }
};