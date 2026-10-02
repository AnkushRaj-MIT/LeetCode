class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        int parA = find(a);
        int parB = find(b);
        if(parA == parB) return;
        if(rank[parA] > rank[parB]) {
            parent[parB] = parA;
        }
        else if(rank[parA] < rank[parB]) {
            parent[parA] = parB;
        }
        else {
            parent[parB] = parA;
            rank[parA]++;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        for(int i = 0; i < n; i++) {
            parent.push_back(i);
            rank.push_back(0);
        }
        for(auto edge : edges) {
            unite(edge[0], edge[1]);
        }
        // Number of nodes in each component
        vector<int> nodes(n, 0);
        for(int i = 0; i < n; i++) {
            nodes[find(i)]++;
        }
        // Number of edges in each component
        vector<int> edgeCount(n, 0);
        for(auto edge : edges) {
            int par = find(edge[0]);
            edgeCount[par]++;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            if(parent[i]!=i) continue;
            int k = nodes[i];
            int requiredEdges = k * (k - 1) / 2;
            if(edgeCount[i] == requiredEdges) {
                ans++;
            }
        }

        return ans;
    }
};