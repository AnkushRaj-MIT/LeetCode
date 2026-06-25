class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int ans=0;
        int zero=0;
        for(int right=0;right<n;right++){
            if(nums[right]==0) zero++;
            while(zero>1){
                if(nums[left]==0) zero--;
                left++;
            }
            ans=max(ans,right-left);//len=(right-left+1)-1
        }
        return ans;
    }
};