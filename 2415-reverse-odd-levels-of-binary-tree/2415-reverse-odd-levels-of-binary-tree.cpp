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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            vector<TreeNode*> odd;
            int n=q.size();
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left!=NULL){
                    q.push(curr->left);
                    if(level%2==0){
                        odd.push_back(curr->left);
                    }
                }
                if(curr->right!=NULL){
                    q.push(curr->right);
                    if(level%2==0){
                        odd.push_back(curr->right);
                    }
                }
            }
            int m=odd.size();
            if(m!=0){
                int l=0,r=m-1;
                while(l<r){
                    swap(odd[l]->val,odd[r]->val);
                    l++;
                    r--;
                }
            }
            level++;
        }
        return root;
    }
};