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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> mp;
        unordered_set<int> children;
        for(vector<int> val:descriptions){
            int parent=val[0];
            int child=val[1];
            bool isLeft=(val[2]==1);
            children.insert(child);
            if(mp.find(parent)==mp.end()) mp[parent]=new TreeNode(parent);
            if(mp.find(child)==mp.end()) mp[child]=new TreeNode(child);
            if(isLeft) mp[parent]->left=mp[child];
            else mp[parent]->right=mp[child];
        }
        for(auto it:mp){
            if(children.find(it.first)==children.end()) return it.second;
        }
        return NULL;
    }
};