class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n=nums.size();
        int left=0;
        int minPos=-1;
        int maxPos=-1;
        long long ans=0;
        for(int right=0;right<n;right++){
            if(nums[right]<minK||nums[right]>maxK){
                left=right+1;
            }
            if(nums[right]==minK){
                minPos=right;
            }
            if(nums[right]==maxK){
                maxPos=right;
            }
            if(maxPos>=left && minPos>=left){
                ans+=min(minPos,maxPos)-left+1;
            }
        }
        return ans;
    }
};