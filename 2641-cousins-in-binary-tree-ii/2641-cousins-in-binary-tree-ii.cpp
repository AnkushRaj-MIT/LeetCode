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
    void bfs1(TreeNode* root,vector<int> &levelSum){
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                sum+=curr->val;
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
            levelSum.push_back(sum);
        }
    }
    TreeNode* replaceValueInTree(TreeNode* root) {
        vector<int> levelSum;
        bfs1(root,levelSum);
        queue<TreeNode*> q;
        q.push(root);
        root->val=0;
        int level=0;
        while(!q.empty()){
            int n=q.size();
            level++;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                int childSum=0;
                if(curr->left) childSum+=curr->left->val;
                if(curr->right) childSum+=curr->right->val;
                if(curr->left){
                    curr->left->val=levelSum[level]-childSum;
                    q.push(curr->left);
                }
                if(curr->right){
                    curr->right->val=levelSum[level]-childSum;
                    q.push(curr->right);
                }
            }
        }
        return root;
    }
};