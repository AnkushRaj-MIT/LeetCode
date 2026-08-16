class Solution {
public:
    vector<int> arr;
    int n;
    Solution(vector<int>& nums) {
        n=nums.size();
        arr=nums;
    }
    
    int pick(int target) {
        int count=0;
        int ans=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==target){
                count++;
                if(rand()%count==0){
                    ans=i;
                }
            }
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */