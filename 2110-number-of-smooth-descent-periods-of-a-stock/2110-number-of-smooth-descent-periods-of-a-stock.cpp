class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=1;
        long long count=1;
        for(int i=1;i<n;i++){
            if(prices[i]==prices[i-1]-1){
                count++;
            }
            else{
                count=1;
            }
            ans+=count;
        }
        return ans;
    }
};