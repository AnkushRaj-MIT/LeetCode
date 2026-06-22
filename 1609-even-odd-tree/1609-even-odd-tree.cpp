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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level=0;
        while(!q.empty()){
            int n=q.size();
            if(level%2==0){
                int val=INT_MIN;
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr->val%2!=1 || curr->val<=val) return false;
                    val=curr->val;
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
            }
            else{
                int val=INT_MAX;
                for(int i=0;i<n;i++){
                    TreeNode* curr=q.front();
                    q.pop();
                    if(curr->val%2!=0 || curr->val>=val) return false;
                    val=curr->val;
                    if(curr->left){
                        q.push(curr->left);
                    }
                    if(curr->right){
                        q.push(curr->right);
                    }
                }
            }
            level++;
        }
        return true;
    }
};