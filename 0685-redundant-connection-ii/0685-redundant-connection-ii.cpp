class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x]=find(parent[x]);
    }  
    bool unite(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB) return false;
        if(rank[parA]==rank[parB]){
            parent[parB]=parA;
            rank[parA]++;
        }
        else if(rank[parA]>rank[parB]){
            parent[parB]=parA;
        }
        else{
            parent[parA]=parB;
        }
        return true;
    }
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<int> par(n+1,0);
        int first=-1,second=-1;
        //find node with two parent
        for(int i=0;i<n;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            if(par[v]==0) par[v]=u;
            else{
                first=i;
                second=-1;
                for(int j=0;j<i;j++){
                    if(edges[j][1]==v){
                        second=j;
                        break;
                    }
                }
                break;
            }
        }
        parent.resize(n+1);
        rank.assign(n+1,0);
        for(int i=1;i<=n;i++) parent[i]=i;
        //to detect cycle,skipping the later edge if needed
        for(int i=0;i<n;i++){
            if(i==first) continue;
            int u=edges[i][0];
            int v=edges[i][1];
            if(!unite(u,v)){
                if(first!=-1) return edges[second];
                return edges[i];
            } 
        }
        return edges[first];
    }
};