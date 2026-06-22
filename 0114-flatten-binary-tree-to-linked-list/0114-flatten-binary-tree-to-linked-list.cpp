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
    void preOrder(TreeNode* root , vector<TreeNode*>& v){
        if(root == NULL) return;
        v.push_back(root);
        preOrder(root->left, v);
        preOrder(root->right, v);
    }
    void flatten(TreeNode* root) {
        vector<TreeNode*> v;
        preOrder(root, v);
        if(v.size() == 0) return;
        int n = v.size();
        for(int i=0; i<n-1; i++){
            v[i]->right = v[i+1];
            v[i]->left = NULL;
        }
        v[n-1]->right = NULL;
        v[n-1]->left = NULL;
    }
};