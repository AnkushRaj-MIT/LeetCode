class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        // frequencyOfPrefix[i] = how many times the shifted prefix sum 'i' has occurred
        vector<int> frequencyOfPrefix(2 * n + 1, 0);
        // Initially, prefix sum = 0
        frequencyOfPrefix[n] = 1;
        // Current shifted prefix sum index
        int shiftedPrefix = n;
        // Number of previous prefix sums that are smaller than the current prefix
        long long smallerPrefixCount = 0;
        // Final answer
        long long majoritySubarrays = 0;
        for (int num : nums) {
            if (num == target) {
                // Prefix sum increases by 1
                // Prefix sums equal to the current value now become smaller
                smallerPrefixCount += frequencyOfPrefix[shiftedPrefix];
                // Move to the new prefix sum
                shiftedPrefix++;
                // Record this new prefix sum
                frequencyOfPrefix[shiftedPrefix]++;
            } else {
                // Prefix sum decreases by 1
                // Move to the new prefix sum
                shiftedPrefix--;
                // Prefix sums equal to this value are no longer smaller
                smallerPrefixCount -= frequencyOfPrefix[shiftedPrefix];
                // Record this new prefix sum
                frequencyOfPrefix[shiftedPrefix]++;
            }
            // Every smaller prefix forms one majority subarray ending here
            majoritySubarrays += smallerPrefixCount;
        }
        return majoritySubarrays;
    }
};