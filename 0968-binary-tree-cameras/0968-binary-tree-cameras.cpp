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
    //instead of leaves try to place cameras on the parents of leaves
    //0->this node needs a camera,1->this node has a camera,2->this node is already covered
    int camera=0;
    int dfs(TreeNode* root){
        if(root==NULL) return 2;
        int left=dfs(root->left);
        int right=dfs(root->right);
        if(left==0||right==0){ //when both or one of the children needs a camera
            camera++;
            return 1;
        }
        else if(left==1||right==1){//when both or one of the children has a camera therefore the parent is also covered
            return 2;
        }
        else return 0;//when both  the children are covered by camera but the parent would need a camera in future
    }
    int minCameraCover(TreeNode* root) {
        if(dfs(root)==0) camera++;
        return camera;
    }
};