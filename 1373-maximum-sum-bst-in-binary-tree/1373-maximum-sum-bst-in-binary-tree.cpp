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
    int ans=0;
    class nodeInfo{
    public:    
        bool isBST;
        int minVal;
        int maxVal;
        int sum;
        nodeInfo(bool bst,int min,int max,int s){
            isBST=bst;
            minVal=min;
            maxVal=max;
            sum=s;
        }
    };
    nodeInfo dfs(TreeNode* root){
        if(root==NULL){
            return nodeInfo(true,INT_MAX,INT_MIN,0);
        }
        nodeInfo left=dfs(root->left);
        nodeInfo right=dfs(root->right);
        if(left.isBST && right.isBST && root->val>left.maxVal && root->val<right.minVal){
            int currSum=left.sum+right.sum+root->val;
            ans=max(ans,currSum);
            return nodeInfo(true,min(root->val,left.minVal),max(root->val,right.maxVal),currSum);
        }
        return nodeInfo(false,INT_MIN,INT_MAX,0);
    }
    int maxSumBST(TreeNode* root) {
        dfs(root);
        return ans;
    }
};