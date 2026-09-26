class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n=s.length();
        unordered_map<string,string> m;
        for(auto val:knowledge){
            m[val[0]]=val[1];
        }
        string ans="";
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                i++;
                string inside="";
                while(i<n && s[i]!=')'){
                    inside+=s[i];
                    i++;
                }
                if(m.find(inside)!=m.end()) ans+=m[inside];
                else ans+='?';
            }
            else ans+=s[i];
        }
        return ans;
    }
};