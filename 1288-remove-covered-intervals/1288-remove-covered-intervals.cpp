class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0]) return a[1]>b[1];
            return a[0]<b[0];
        });
        int n=intervals.size();
        int end=intervals[0][1];
        int ans=n;
        for(int i=1;i<n;i++){
            int y=intervals[i][1];
            if(y<=end){
                ans--;
            }
            else{
                end=y;
            }
        }
        return ans;
    }
};