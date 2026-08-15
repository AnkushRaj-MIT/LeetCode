class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int xr=0;
        bool nonzero=false;
        for(int num:nums){
            xr^=num;
            if(num!=0) nonzero=true;
        }
        if(xr!=0) return n;
        if(!nonzero) return 0;
        return n-1;
    }
};