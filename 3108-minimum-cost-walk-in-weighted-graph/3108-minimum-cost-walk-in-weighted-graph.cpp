class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void unite(int a,int b){
        int parA=find(a);
        int parB=find(b);
        if(parA==parB) return;
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
    }
    int find(int val){
        if(parent[val]==val)return val;
        return parent[val]=find(parent[val]);
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        for(auto edge:edges){
            unite(edge[0],edge[1]);
        }
        vector<int> cost(n,-1);
        for(auto edge:edges){
            int par=find(edge[0]);
            if(cost[par]==-1) cost[par]=edge[2];
            else cost[par] &= edge[2];
        }
        vector<int> ans;
        for(auto q:query){
            int u=q[0];
            int v=q[1];
            if(find(u)!=find(v)){
                ans.push_back(-1);
            }
            else if(u==v){
                ans.push_back(0);
            }
            else{
                ans.push_back(cost[find(u)]);
            }
        }
        return ans;
    }
};