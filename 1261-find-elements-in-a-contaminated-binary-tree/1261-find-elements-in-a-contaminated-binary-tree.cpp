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
class FindElements {
public:
    TreeNode* root;
    unordered_set<int> s;
    void dfs(TreeNode* root,long long i){
        if(root==NULL) return;
        root->val=i;
        s.insert(i);
        if(root->left) dfs(root->left,2*i+1);
        if(root->right) dfs(root->right,2*i+2);
    }
    FindElements(TreeNode* r) {
        root=r;
        dfs(root,0);
    }
    
    bool find(int target) {
        if(s.find(target)!=s.end()) return true;
        return false;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */