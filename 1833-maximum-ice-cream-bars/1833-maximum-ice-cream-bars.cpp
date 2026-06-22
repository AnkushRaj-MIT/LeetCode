class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int maxcost=*max_element(costs.begin(),costs.end());
        vector<int> freq(maxcost+1,0);
        for(int i=0;i<n;i++){
            freq[costs[i]]++;
        }
        int ans=0;
        for(int cost=1;cost<maxcost+1;cost++){
            int buyablecount=coins/cost;
            if(freq[cost]>=buyablecount){
                ans+=buyablecount;
                break;
            }
            else{
                ans+=freq[cost];
                coins-=cost*freq[cost];
            }
        }
        return ans;
    }
};