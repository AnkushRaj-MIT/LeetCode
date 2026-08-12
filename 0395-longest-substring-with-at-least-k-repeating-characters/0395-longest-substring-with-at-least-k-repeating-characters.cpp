class Solution {
public: 
    int solve(string s,int left,int right,int k){
        if(right-left+1<k) return 0;
        unordered_map<char,int> freq;
        for(int i=left;i<=right;i++){
            freq[s[i]]++;
        }
        for(int i=left;i<=right;i++){
            if(freq[s[i]]<k){
                int j=i+1;
                while(j<=right && freq[s[j]]<k) j++;
                return max( solve(s,left,i-1,k) , solve(s,j,right,k));
            }
        }
        return right-left+1;
    }
    int longestSubstring(string s, int k) {
        int n=s.length();
        return solve(s,0,n-1,k);
    }
};