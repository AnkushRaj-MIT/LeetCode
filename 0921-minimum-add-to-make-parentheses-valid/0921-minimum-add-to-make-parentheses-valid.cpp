class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.size();
        int ans =0,open=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') open++;
            else open--;
            if(open<0){
                ans++;
                open=0;
            }
        }
        ans += open;
        return ans;
    }
};