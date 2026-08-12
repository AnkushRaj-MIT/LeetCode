class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        int left=0;
        int ans=0;
        for(int right=0;right<nums.size();right++){
            m[nums[right]]++;
            while(m[nums[right]]>k){
                m[nums[left]]--;
                if(m[nums[left]]==0) m.erase(nums[left]);
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};