class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long ans=0;
        for(int i=0;i<n;i++){
            nums[i]=abs(nums[i]);
        }
        sort(nums.begin(),nums.end());
        int i=0,j=n-1;
        while(i<j){
            ans+=(long long)(nums[j]*nums[j]);
            ans-=(long long)(nums[i]*nums[i]);
            i++;
            j--;
        }
        if(i==j) ans+=(long long)(nums[j]*nums[j]);
        return ans;
    }
};