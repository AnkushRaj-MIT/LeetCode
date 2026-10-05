class Solution {
public:
class DSU{
public:
    vector<int> parent;
    vector<int> rank;
    DSU(int n){
        for(int i=0;i<n;i++){
            parent.push_back(i);
            rank.push_back(0);
        }
    }
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
        else parent[parA]=parB;
    }
    int find(int val){
        if(parent[val]==val) return val;
        return parent[val]=find(parent[val]);
    }
};
    int getMST(int n,vector<vector<int>> & edges,int skip,int force){
        DSU dsu(n);
        int cost=0,count=0;
        if(force!=-1){
            int u=edges[force][0];
            int v=edges[force][1];
            int wt=edges[force][2];
            dsu.unite(u,v);
            cost+=wt;
            count++;
        }
        for(int i=0;i<edges.size();i++){
            if(i==skip||i==force) continue;
            auto edge=edges[i];
            int u=edge[0];
            int v=edge[1];
            int wt=edge[2];
            if(dsu.find(u)!=dsu.find(v)){
                dsu.unite(u,v);
                cost+=wt;
                count++;
            }
        }
        if(count!=n-1) return INT_MAX;
        return cost;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int i=0;
        for(auto &edge:edges){
            edge.push_back(i);
            i++;
        }
        sort(edges.begin(),edges.end(),[](auto &a,auto &b){
            return a[2]<b[2];
        });
        int originalMST=getMST(n,edges,-1,-1);
        vector<int> critical;
        vector<int> pseudoCritical;
        for(int i=0;i<edges.size();i++){
            int without=getMST(n,edges,i,-1);
            if(without>originalMST){
                critical.push_back(edges[i][3]);
                continue;
            }
            int with=getMST(n,edges,-1,i);
            if(with==originalMST){
                pseudoCritical.push_back(edges[i][3]);
            }
        }
        return {critical,pseudoCritical};
    }
};