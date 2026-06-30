class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.length();
        int count=0;
        vector<int> lastidx(3,-1);
        for(int i=0;i<n;i++){
            lastidx[s[i]-'a']=i;
            if(lastidx[0]!=-1&&lastidx[1]!=-1&&lastidx[2]!=-1){
                count+=(1+min({lastidx[0],lastidx[1],lastidx[2]}));
            }
        }
        return count;
    }
};