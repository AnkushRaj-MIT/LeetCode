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
    TreeNode* recoverFromPreorder(string traversal) {
       int n=traversal.length();
       stack<TreeNode*> st;
       int i=0;
       while(i<n){
            int depth=0;
            while(i<n && traversal[i]=='-'){
                depth++;
                 i++;
            }
            int val=0;
            while(i<n && isdigit(traversal[i])){
                val=val*10+(traversal[i]-'0');
                i++;
            }
            TreeNode* node=new TreeNode(val);
            while(st.size()>depth) st.pop();
            if(!st.empty()){
                if(st.top()->left==NULL){
                    st.top()->left=node;   
                }
                else st.top()->right=node;
            }
            st.push(node);
       }
       while(st.size()>1)st.pop();
       return st.top();
    }
};