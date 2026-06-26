class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cummulativeSum=0;
        unordered_map<int,int> m;
        m[0]=1;
        long long ans=0;
        int validLeftPoints=0;
        for(int val:nums){
            if(val==target){
                validLeftPoints+=m[cummulativeSum];
                cummulativeSum++;
            }else{
                cummulativeSum--;
                validLeftPoints-=m[cummulativeSum];
            }
            m[cummulativeSum]++;
            ans+=validLeftPoints;
        }
        return ans;
    }
};