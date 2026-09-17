class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        int total=0;
        for(int num:nums){
            total+=num;
        }
        //we need to find the longest subarray with sum=total-x
        if(total<x) return -1;
        int maxLen=INT_MIN;
        int left=0;
        int sum=0;
        for(int right=0;right<n;right++){
            sum+=nums[right];
            while(sum>total-x){
                sum-=nums[left];
                left++;
            }
            if(sum==total-x){
                int len=right-left+1;
                maxLen=max(maxLen,len);
            }
        }
        return maxLen==INT_MIN? -1:n-maxLen;
    }
};