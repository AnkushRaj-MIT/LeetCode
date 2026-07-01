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
    int minSwaps(vector<int> arr){
        int n=arr.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) v.push_back({arr[i],i});
        sort(v.begin(),v.end());
        vector<bool> visited(n,false);
        int swaps=0;
        for(int i=0;i<n;i++){
            if(visited[i]||v[i].second==i) continue;
            int cycle=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=v[j].second;;
                cycle++;
            }
            swaps+=cycle-1;
        }
        return swaps;
    }
    int minimumOperations(TreeNode* root) {
        int ans=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            vector<int> level;
            for(int i=0;i<n;i++){
                TreeNode* curr=q.front();
                q.pop();
                level.push_back(curr->val);
                if(curr->left){
                    q.push(curr->left);
                }
                if(curr->right){
                    q.push(curr->right);
                }
            }
            ans+=minSwaps(level);
        }
        return ans;
    }
};