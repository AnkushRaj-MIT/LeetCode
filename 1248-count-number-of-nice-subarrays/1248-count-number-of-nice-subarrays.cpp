class Solution {
public:
    int atmost(vector<int> &nums,int k){
        int count=0;
        int n=nums.size();
        if(k>n) return 0;
        int oddCount=0;
        int left=0;
        for(int right=0;right<n;right++){
            if(nums[right]%2==1) oddCount++;
            while(oddCount>k){
                if(nums[left]%2==1) oddCount--;
                left++;
            }
            count+=(right-left+1);//atmost k no. of oddNumbers are allowed in this case(can be less than k too)
        }
        return count;
    }
    int numberOfSubarrays(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};