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

    // Encodes a tree to a single string.
    void preorder(TreeNode* root,string &ans){
        if(root==NULL){
            ans+="# ";
            return;
        }
        ans+=to_string(root->val)+" ";
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* buildTree(vector<string>&nodes,int &index){
        if(nodes[index]=="#"){
            index++;
            return NULL;
        }
        TreeNode* root=new TreeNode(stoi(nodes[index++]));
        root->left=buildTree(nodes,index);
        root->right=buildTree(nodes,index);
        return root;
    }
    TreeNode* deserialize(string data) {
        vector<string>nodes;
        stringstream ss(data);
        string temp;
        while(ss>>temp){
            nodes.push_back(temp);
        }
        int index=0;
        return buildTree(nodes,index);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));