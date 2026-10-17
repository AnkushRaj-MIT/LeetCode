class Solution {
public:
    int digitSum(int val) {
        int sum = 0;
        while(val > 0) {
            sum += val % 10;
            val /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;
        for(int i = 0; i < n; i++) {
            arr.push_back({digitSum(nums[i]), nums[i]});
        }
        sort(arr.begin(), arr.end());
        unordered_map<int, int> pos;
        for(int i = 0; i < n; i++) {
            pos[arr[i].second] = i;
        }
        vector<bool> vis(n, false);
        int swaps = 0;
        for(int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int j = i, count = 0;
            while(!vis[j]) {
                vis[j] = true;
                j = pos[nums[j]];
                count++;
            }
            swaps += count - 1;
        }
        return swaps;
    }
};