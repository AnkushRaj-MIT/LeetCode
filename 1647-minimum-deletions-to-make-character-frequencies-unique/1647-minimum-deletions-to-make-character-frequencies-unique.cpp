class Solution {
public:
    int minDeletions(string str) {
        vector<int> freq(26,0);
        unordered_set<int> s;
        for(char  ch:str){
            freq[ch-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            if(freq[i]==0) break;
            while(freq[i]>0 && s.find(freq[i])!=s.end()){
                ans++;
                freq[i]--;
            }
            s.insert(freq[i]);
        }
        return ans;
    }
};