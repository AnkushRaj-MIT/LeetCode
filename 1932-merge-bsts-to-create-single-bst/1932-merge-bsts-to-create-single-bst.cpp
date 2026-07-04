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
    unordered_set<int> vis;
    bool dfs(TreeNode* root,TreeNode* min,TreeNode* max,unordered_map<int,TreeNode*> &mp){
        if(root==NULL) return true;
        if(vis.count(root->val)) return false;
        vis.insert(root->val);
        if(min!=NULL && root->val<=min->val) return false;
        if(max!=NULL && root->val>=max->val) return false;
        if(root->left==NULL && root->right==NULL){
            auto it=mp.find(root->val);
            if(it!=mp.end()){
                TreeNode* other=it->second;
                root->left=other->left;
                root->right=other->right;
                mp.erase(it);
            }
        }
        return  dfs(root->left,min,root,mp) && dfs(root->right,root,max,mp);
    }
    void findLeaves(TreeNode* root,unordered_set<int> &leaves){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            leaves.insert(root->val);
        }
        if(root->left) findLeaves(root->left,leaves);
        if(root->right) findLeaves(root->right,leaves);
    }
    TreeNode* canMerge(vector<TreeNode*>& trees) {
        int n=trees.size();
        if(n==1) return trees[0];
        unordered_map<int,TreeNode*> mp;
        for(auto tree:trees){
            mp[tree->val]=tree;
        }
        unordered_set<int> leaves;
        for(auto tree:trees){
            findLeaves(tree,leaves);
        }
        TreeNode* root=NULL;
        for(auto tree:trees){
            if(leaves.find(tree->val)==leaves.end()){
                if(root!=NULL) return NULL;
                root=tree;
            }
        }
        if(root==NULL) return NULL;
        mp.erase(root->val);
        bool isPossible=dfs(root,NULL,NULL,mp);
        if(!isPossible || !mp.empty()) return NULL;
        return root;
    }
};