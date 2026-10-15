class Solution {
public:
    vector<int> parent,rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }
    void unite(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB) return;
        if(rank[parA]>rank[parB]){
            parent[parB]=parA;
        }
        else if(rank[parA]==rank[parB]){
            rank[parA]++;
            parent[parB]=parA;
        }
        else{
            parent[parA]=parB;
        }
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int total=row*col;
        int top=total;
        int bottom=total+1;
        parent.resize(total+2);
        rank.assign(total+2,0);
        for(int i=0;i<total+2;i++) parent[i]=i;
        vector<vector<int>> grid(row,vector<int> (col,0));
        int dx[]={1,-1,0,0};
        int dy[]={0,0,1,-1};
        for(int i=total-1;i>=0;i--){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            grid[r][c]=1;
            int id=r*col+c;
            if(r==0) unite(id,top);
            if(r==row-1) unite(id,bottom);
            for(int k=0;k<4;k++){
                int x=r+dx[k];
                int y=c+dy[k];
                if(x>=0 && x<row && y>=0 && y<col && grid[x][y]==1){
                    unite(id,x*col+y);
                }
            }
            if(find(top)==find(bottom)) return i;
        }
        return 0;
    }
};