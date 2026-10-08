class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans;
        int count=0;
        for(char ch:s){
            if(ch=='('){
                if(count>0) ans.push_back(ch);
                count++;
            }else{ 
                count--;
                if(count>0) ans.push_back(ch);
            }
        }
        return ans;
    }
};