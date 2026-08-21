class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;//{height,{row,col}}
        int m=heightMap.size();
        int n=heightMap[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false)); 
        for(int i=0;i<n;i++){
            pq.push({heightMap[0][i],{0,i}});
            vis[0][i]=true;
            pq.push({heightMap[m-1][i],{m-1,i}});
            vis[m-1][i]=true;
        }
        for(int i=1;i<m-1;i++){
            pq.push({heightMap[i][0],{i,0}});
            vis[i][0]=true;
            pq.push({heightMap[i][n-1],{i,n-1}});
            vis[i][n-1]=true;
        }
        int ans=0;
        int rowDirection[]={-1,1,0,0};
        int colDirection[]={0,0,-1,1};
        while(!pq.empty()){
            auto curr=pq.top();
            pq.pop();
            int height=curr.first;
            int row=curr.second.first;
            int col=curr.second.second;
            for(int k=0;k<4;k++){
                int newRow=row+rowDirection[k];
                int newCol=col+colDirection[k];
                if(newRow>=0 && newRow<m && newCol>=0 && newCol<n && !vis[newRow][newCol]){
                    vis[newRow][newCol]=true;
                    ans+=max(0,height-heightMap[newRow][newCol]);
                    pq.push({max(height,heightMap[newRow][newCol]),{newRow,newCol}});
                }
            }
        }
        return ans;
    }
};