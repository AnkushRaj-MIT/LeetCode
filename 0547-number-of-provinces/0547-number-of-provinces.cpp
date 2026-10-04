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
        if(parent[val]==val) return val;
        return parent[val]=find(parent[val]);
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1){
                    unite(i,j);
                }
            }
        }
        unordered_set<int> s;
        for(int i=0;i<n;i++){
            s.insert(find(i));
        }
        return s.size();
    }
};