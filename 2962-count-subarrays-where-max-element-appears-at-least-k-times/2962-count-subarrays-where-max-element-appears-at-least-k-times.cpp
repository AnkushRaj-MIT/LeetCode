class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int maxm=*max_element(nums.begin(),nums.end());
        int n=nums.size();
        int left=0;
        int maxCount=0;
        long long ans=0;
        for(int right=0;right<n;right++){
            if(nums[right]==maxm) maxCount++;
            while(maxCount==k){
                ans+=(long long)n-right;
                if(nums[left]==maxm) maxCount--;
                left++;
            }
        }
        return ans;
    }
};