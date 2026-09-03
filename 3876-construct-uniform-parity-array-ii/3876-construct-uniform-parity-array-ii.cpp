class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        int n=nums.size();
        int smallestEven=INT_MAX;
        int smallestOdd=INT_MAX;
        bool even=nums[0]%2==0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                smallestEven=min(smallestEven,nums[i]);
            }
            else{
                smallestOdd=min(smallestOdd,nums[i]);
            }
        }
        if(smallestEven==INT_MAX||smallestOdd==INT_MAX) return true;
        return smallestOdd<smallestEven;
    }
};