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
    TreeNode* makeParent(TreeNode* root,unordered_map<TreeNode*,TreeNode*> &parent,int start){
        queue<TreeNode*> q;
        q.push(root);
        TreeNode* startNode=NULL;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->val==start) startNode=curr;
            if(curr->left){
                parent[curr->left]=curr;
                q.push(curr->left);
            }
            if(curr->right){
                parent[curr->right]=curr;
                q.push(curr->right);
            }
        }
        return startNode;
    }
    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*> parent;
        TreeNode* startNode=makeParent(root,parent,start);
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(startNode);
        visited[startNode]=true;
        int time=0;
        while(!q.empty()){
            int n=q.size();
            bool spread=false;
            while(n--){
                TreeNode* curr=q.front();
                q.pop();
                if(curr->left && !visited[curr->left]){
                    visited[curr->left]=true;
                    q.push(curr->left);
                    spread=true;
                }
                if(curr->right && !visited[curr->right]){
                    visited[curr->right]=true;
                    q.push(curr->right);
                    spread=true;
                }
                if(parent.count(curr) && !visited[parent[curr]]){
                    visited[parent[curr]]=true;
                    q.push(parent[curr]);
                    spread=true;
                }
            }
            if(spread) time++;
        }
        return time;
    }
};