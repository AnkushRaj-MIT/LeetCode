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
    string serialize(TreeNode* root) {
        string  data="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            if(curr==NULL){
                data.append("N,");
            }
            else{
                data.append(to_string(curr->val)+",");
            }
            if(curr!=NULL){
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return data;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        stringstream s(data);
        string  str;
        getline(s,str,',');
        if(str=="N") return NULL;
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curr=q.front();
            q.pop();
            getline(s,str,',');
            if(str=="N"){
                curr->left=NULL;
            }
            else{
                TreeNode* LeftNode=new TreeNode(stoi(str));
                curr->left=LeftNode;
                q.push(LeftNode);
            }
            getline(s,str,',');
            if(str=="N"){
                curr->right=NULL;
            }
            else{
                TreeNode* RightNode=new TreeNode(stoi(str));
                curr->right=RightNode;
                q.push(RightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;