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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            bool foundX=false;
            bool foundY=false;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                bool found=false;
                q.pop();
                if(curr->left){
                    q.push(curr->left);
                    if(curr->left->val==x){
                        foundX=true;
                        found=true;
                    }
                    if(curr->left->val==y){
                        foundY=true;
                        found=true;
                    }
                }
                if(curr->right){
                    q.push(curr->right);
                    if(curr->right->val==x){
                        foundX=true;
                        if(found) return false;
                    }
                    if(curr->right->val==y){
                        foundY=true;
                        if(found) return false;
                    }
                }
            }
            if(foundX && foundY) return true;
            if(foundX || foundY) return false;
        }
        return false;
    }
};