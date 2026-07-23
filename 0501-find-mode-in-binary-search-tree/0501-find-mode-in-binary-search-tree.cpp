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
    unordered_map<int,int> freq;
    void inorder(TreeNode* root){
        if(root==NULL) return;
        inorder(root->left);
        freq[root->val]++;
        inorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        if(root==NULL) return {};
        vector<pair<int,int>> p(freq.begin(),freq.end());
        sort(p.begin(),p.end(),[](pair<int,int> a,pair<int,int> b){
            return a.second>b.second;
        });
        vector<int> ans;
        int maxm=INT_MIN;
        for(auto val:p){
            maxm=max(maxm,val.second);
            if(val.second==maxm) ans.push_back(val.first);
        }
        return ans;
    }
};