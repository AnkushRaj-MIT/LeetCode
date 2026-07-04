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
    TreeNode* buildBST(vector<int> nums,int st,int end){
        if(st>end) return NULL;
        int maxElement=INT_MIN;
        int maxIdx=-1;
        int i=st;
        for (int i = st; i <= end; i++) {
            if (nums[i] > maxElement) {
                maxElement = nums[i];
                maxIdx = i;
            }
        }
        TreeNode* root=new TreeNode(maxElement);
        root->left=buildBST(nums,st,maxIdx-1);
        root->right=buildBST(nums,maxIdx+1,end);
        return root;
    }
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n=nums.size();
        return buildBST(nums,0,n-1);
    }
};