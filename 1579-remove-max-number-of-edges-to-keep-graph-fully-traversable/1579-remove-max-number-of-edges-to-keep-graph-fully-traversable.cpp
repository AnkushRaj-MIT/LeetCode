class Solution {
public:
    class DSU {
    public:
        vector<int> parent;
        vector<int> rank;
        DSU(int n) {
            rank.assign(n, 0);
            for(int i = 0; i < n; i++)
                parent.push_back(i);
        }
        int find(int x) {
            if(parent[x] == x) return x;
            return parent[x] = find(parent[x]);
        }
        bool unite(int a, int b) {
            int parA = find(a);
            int parB = find(b);
            if(parA == parB) return false;
            if(rank[parA] == rank[parB]) {
                parent[parB] = parA;
                rank[parA]++;
            }
            else if(rank[parA] > rank[parB]) {
                parent[parB] = parA;
            }
            else {
                parent[parA] = parB;
            }
            return true;
        }
    };
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);
        int ans = 0;
        // Type 3
        for(auto edge : edges) {
            if(edge[0] == 3) {
                bool a = alice.unite(edge[1]-1, edge[2]-1);
                bool b = bob.unite(edge[1]-1, edge[2]-1);
                if(!a && !b) ans++;
            }
        }
        // Type 2
        for(auto edge : edges) {
            if(edge[0] == 2) {
                if(!bob.unite(edge[1]-1, edge[2]-1)) ans++;
            }
        }
        // Type 1
        for(auto edge : edges) {
            if(edge[0] == 1) {
                if(!alice.unite(edge[1]-1, edge[2]-1)) ans++;
            }
        }
        int rootAlice = alice.find(0);
        int rootBob = bob.find(0);
        for(int i = 1; i < n; i++) {
            if(alice.find(i) != rootAlice ||
               bob.find(i) != rootBob) {
                return -1;
            }
        }
        return ans;
    }
};