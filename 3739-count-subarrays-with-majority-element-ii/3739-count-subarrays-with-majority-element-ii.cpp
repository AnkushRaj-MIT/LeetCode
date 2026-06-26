class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> pre(2*n+1,0);
        //if nums[i]==target then +1 otherwise -1 ,therefore pre will vary from -n to +n (total 2n+1)
        //negative indices aren't allowed therefore n is the origin
        pre[n]=1;//means prefix sum zero has appeared once(before starting)
        //pre[6]=4 means prefix sum corrsponding to index 6 has appeared  four times
        int count=n;//stores current prefix sum+shift
        //sum=target+others OR sum=prefix[R]-prefix[L-1],if sum>0 then its a majority subarray
        //therefor prefix[R]>prefix[L-1],for position r we need to find the no. of previous prefix sum that are smaller than prefix[R]
        long long ans=0,preSum=0;
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                preSum+=pre[count];
                count++;
            }
            else{
                count--;
                preSum-=pre[count];
            }
            pre[count]++;
            ans+=preSum;
        }
        return ans;
    }
};