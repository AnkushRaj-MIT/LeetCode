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
class CBTInserter {
public:
    TreeNode* root;
    CBTInserter(TreeNode* root) {
        this->root=root;
    }
    
    int insert(int val) {
        queue<TreeNode*> q;
        q.push(root);
        int parVal;
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr->left==NULL){
                parVal=curr->val;
                curr->left=new TreeNode(val);
                break;
            }
            else if(curr->left) q.push(curr->left);
            if(curr->right==NULL){
                parVal=curr->val;
                curr->right=new TreeNode(val);
                break;
            }
            else if(curr->right) q.push(curr->right);
        }
        return parVal;
    }
    
    TreeNode* get_root() {
        return root;
    }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(val);
 * TreeNode* param_2 = obj->get_root();
 */