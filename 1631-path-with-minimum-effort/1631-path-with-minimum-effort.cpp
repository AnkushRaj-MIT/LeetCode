class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> dist(m,vector<int> (n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        dist[0][0]=0;
        int dr[]={-1,1,0,0};
        int dc[]={0,0,1,-1};
        while(!pq.empty()){
            auto val=pq.top();
            pq.pop();
            int effort=val.first;
            int row=val.second.first;
            int col=val.second.second;
            for(int i=0;i<4;i++){
                int nr=row+dr[i];
                int nc=col+dc[i];
                if(nr>=0 && nc>=0 &&  nr<m && nc<n){
                    int newEffort=max(effort,abs(heights[row][col]-heights[nr][nc]));
                    if(newEffort<dist[nr][nc]){
                        dist[nr][nc]=newEffort;
                        pq.push({newEffort,{nr,nc}});
                    }
                }
            }
        }
        return dist[m-1][n-1];
    }
};