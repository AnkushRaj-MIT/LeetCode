class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minIdx = 0, maxIdx = 0;
        for (int i = 1; i < n; i++) {
            if (nums[i] < nums[minIdx]) minIdx = i;
            if (nums[i] > nums[maxIdx]) maxIdx = i;
        }
        int left = min(minIdx, maxIdx) + 1;
        int right = max(minIdx, maxIdx) + 1;
        int case1 = right;
        int case2 = n - left + 1;
        int case3 = left + (n - right + 1);
        return min({case1, case2, case3});
    }
};