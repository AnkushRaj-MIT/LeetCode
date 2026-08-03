class Solution {
public:
    class Graph{
        int V;
        list<int> *l;
    public:
        Graph(int V){
            this->V=V;
            l=new list<int>[V+1];
        }
        void addEdge(int u,int v){
            l[u].push_back(v);
            l[v].push_back(u);
        }
        bool bfs(int u,vector<bool> &vis){
            queue<pair<int,int>> q;
            q.push({u,-1});
            vis[u]=true;
            while(!q.empty()){
                int src=q.front().first;
                int parent=q.front().second;
                q.pop();
                for(int v:l[src]){
                    if(!vis[v]){
                        vis[v]=true;
                        q.push({v,src});
                    }
                    else if(v!=parent) return true;
                }
            }
            return false;
        }
        bool hasCycle(){
            vector<bool> vis(V+1,false);
            for(int i=1;i<V;i++){
                if(!vis[i]){
                    if(bfs(i,vis)) return true;
                }
            }
            return false;
        }
    };
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        Graph g(n);
        for(auto edge:edges){
            int u=edge[0];
            int v=edge[1];
            g.addEdge(u,v);
            if(g.hasCycle()) return edge;
        }
        return {};
    }
};