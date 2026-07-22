class Solution {
public:
    int atmost(vector<int> &nums,int k){
        unordered_map<int,int> freq;
        int n=nums.size();
        int left=0;
        int ans=0;
        for(int right=0;right<n;right++){
            freq[nums[right]]++;
            while(freq.size()>k){
                freq[nums[left]]--;
                if(freq[nums[left]]==0) freq.erase(nums[left]);
                left++;
            }
            ans+=(right-left+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k)-atmost(nums,k-1);
    }
};