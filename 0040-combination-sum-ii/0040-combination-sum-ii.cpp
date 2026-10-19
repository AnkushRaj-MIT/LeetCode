class Solution {
public:
    void solver(vector<int>& nums, int idx, int tar,vector<int>& combin, vector<vector<int>>& ans) {
        if(tar == 0) {
            ans.push_back(combin);
            return;
        }
        if(idx == nums.size() || tar < 0) return;
        for(int i = idx; i < nums.size(); i++) {
            if(i > idx && nums[i] == nums[i-1]) continue;
            combin.push_back(nums[i]);
            solver(nums, i+1, tar-nums[i], combin, ans);
            combin.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> combin;
        solver(nums, 0, target, combin, ans);
        return ans;
    }
};