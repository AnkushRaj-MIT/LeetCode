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
class BSTIterator {
private:
    vector<int> inorder;
    int idx;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        dfs(root->left);
        inorder.push_back(root->val);
        dfs(root->right);
    }    
public:
    BSTIterator(TreeNode* root) {
        idx=0;
        dfs(root);
    }
    
    int next() {
        return inorder[idx++];
    }
    
    bool hasNext() {
        return idx<inorder.size();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */