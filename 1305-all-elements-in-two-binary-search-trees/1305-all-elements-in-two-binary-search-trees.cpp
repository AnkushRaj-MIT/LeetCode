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
    void buildArray(TreeNode* root,vector<int> &vec){
        if(root==NULL) return;
        buildArray(root->left,vec);
        vec.push_back(root->val);
        buildArray(root->right,vec);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> v1;
        buildArray(root1,v1);
        vector<int> v2;
        buildArray(root2,v2);
        int m=v1.size();
        int n=v2.size();
        vector<int> ans;
        int i=0,j=0;
        while(i<m && j<n){
            if(v1[i]<=v2[j]){
                ans.push_back(v1[i++]);
            }
            else ans.push_back(v2[j++]);
        }
        while(i<m){
            ans.push_back(v1[i++]);
        }
        while(j<n){
            ans.push_back(v2[j++]);
        }
        return ans;
    }
};