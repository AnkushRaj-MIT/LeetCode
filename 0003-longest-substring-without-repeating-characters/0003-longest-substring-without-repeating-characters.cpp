class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> u;
        int n=s.length();
        int ans=0;
        int curr=0;
        int left=0;
        for(int right=0;right<n;right++){
            char ch=s[right];
            while(u.find(ch)!=u.end()){
                u.erase(s[left]);
                left++;
                curr--;
            }
            u.insert(ch);
            curr++;
            ans=max(ans,curr);
        }
        return ans;
    }
};