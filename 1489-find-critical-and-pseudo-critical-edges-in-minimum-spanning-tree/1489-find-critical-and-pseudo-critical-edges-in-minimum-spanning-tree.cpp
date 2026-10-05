class Solution {
public:
    int findParent(int node , vector<int>&parent){
        if(parent[node] == node){
            return parent[node];
        }

        return parent[node] = findParent(parent[node],parent);
    }

    bool unionSet(int u ,int v, vector<int>&parent,vector<int>&rank){
        u = findParent(u,parent);
        v = findParent(v,parent);

        if(u == v){
            return false;
        }

        if(rank[u]>rank[v]){
            parent[v] = u;
        }
        else if(rank[u]<rank[v]){
            parent[u] = v;
        }
        else{
            parent[u] = v;
            rank[v]++;
        }
        return true;
    }
    int kruskal(int n , vector<vector<int>>&edges,int skip ,int force){
        vector<int>parent(n);
        vector<int>rank(n,0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int weight = 0;
        int count = 0;
        if(force != -1){
           
            int u = edges[force][0];
            int v = edges[force][1];
            int w = edges[force][2];


            if (unionSet(u, v, parent, rank)) {
                weight += w;
                count++;
            }
        }

        for (int i = 0; i < edges.size(); i++) {

            // Don't use the skipped edge
            if (i == skip)
                continue;

            // Already forced
            if (i == force)
                continue;

            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];

            if (unionSet(u, v, parent, rank)) {

                weight += w;
                count++;

                // MST has n-1 edges
                if (count == n - 1)
                    break;
            }
        }

        if(count != n-1){
            return INT_MAX;
        }

        return weight;

    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
       vector<vector<int>>newEdges;
       for(int i=0;i<edges.size();i++){
        newEdges.push_back({
            edges[i][0],
            edges[i][1],
            edges[i][2],
            i
        });
       }
       sort(newEdges.begin(), newEdges.end(),
            [](const vector<int>& a, const vector<int>& b) {
                return a[2] < b[2];
            }
        );
       int originalWeight = kruskal(n,newEdges,-1,-1);
       vector<int>critical;
       vector<int>pseudo;
       for(int i =0;i<newEdges.size();i++){
         int withoutEdge = kruskal(n,newEdges,i,-1);
         if(withoutEdge>originalWeight){
            critical.push_back(newEdges[i][3]);
         }
         else{
            int withEdge = kruskal(n,newEdges,-1,i);
            if(withEdge == originalWeight){
                pseudo.push_back(newEdges[i][3]);
            }
         }
       }
       return {
        critical,
        pseudo
       };
       
    }
    
};