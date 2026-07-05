/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void preorder(TreeNode* & root,string & ans){
        if(root==NULL){
            ans += "#,";
            return ;
        }
        ans += to_string(root->val) + ',';
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
       string ans ="";
       preorder(root,ans);
       return ans;
    }
    TreeNode * create(stringstream & ss){
        string current = "";
        if(!getline(ss,current,','))return NULL;
        if(current == "#")return NULL;
        TreeNode* root = new TreeNode(stoi(current));
        root->left = create(ss);
        root->right = create(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return create(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;