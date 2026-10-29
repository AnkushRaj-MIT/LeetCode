class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        int ans=-1;
        vector<int> vis(n,0);
        vector<int> time(n,0);
        int t=1;
        for(int i=0;i<n;i++){
            if(vis[i]) continue;
            int curr=i;
            int start=t;
            while(curr!=-1 && !vis[curr]){
                vis[curr]=1;
                time[curr]=t++;
                curr=edges[curr];
            }
            if(curr!=-1 && time[curr]>=start){
                ans=max(ans,t-time[curr]);
            }
        }
        return ans;
    }   
};