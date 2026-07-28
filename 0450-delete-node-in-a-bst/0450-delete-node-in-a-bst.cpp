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
    TreeNode* inorderSuccesor(TreeNode* node){
        while(node!=NULL&&node->left!=NULL){
            node=node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(root->left==NULL&&root->right==NULL){
                delete root;
                return NULL;
            }
            else if(root->left!=NULL&&root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            else if(root->right!=NULL&&root->left==NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            else{
                TreeNode* IS=inorderSuccesor(root->right);
                root->val=IS->val;
                root->right=deleteNode(root->right,IS->val);
            }
        }
        return root;
    }
};