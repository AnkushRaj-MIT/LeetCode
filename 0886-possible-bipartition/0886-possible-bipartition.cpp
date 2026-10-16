class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    void unite(int a,int b){
        int  parA=find(a);
        int parB=find(b);
        if(parA==parB) return;
        if(rank[parA]==rank[parB]){
            rank[parA]++;
            parent[parB]=parA;
        }
        else if(rank[parA]>rank[parB]){
            parent[parB]=parA;
        }
        else{
            parent[parA]=parB;
        }
    }
    int find(int val){
        if(parent[val]==val) return val;
        return parent[val]=find(parent[val]);
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        parent.resize(2*n+1);
        rank.assign(2*n+1,0);
        for(int i=0;i<2*n+1;i++) parent[i]=i;
        for(auto num:dislikes){
            int a=num[0];
            int b=num[1];
            if(find(a)==find(b)) return false;
            unite(a,b+n);
            unite(b,a+n);
        }
        return true;
    }
};