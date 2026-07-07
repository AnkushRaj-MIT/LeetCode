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
    void inorder(TreeNode* root,vector<TreeNode*> &vec){
        if(root==NULL) return;
        inorder(root->left,vec);
        vec.push_back(root);
        inorder(root->right,vec);
    }
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> vec;
        inorder(root,vec);
        int n=vec.size();
        TreeNode* n1=NULL;
        TreeNode* n2=NULL;
        for(int i=0;i<n-1;i++){
            if(vec[i]->val>vec[i+1]->val){
                if(n1==NULL){
                    n1=vec[i];
                    n2=vec[i+1];
                }
                else n2=vec[i+1];
            }
        }
        swap(n1->val,n2->val);
    }
};