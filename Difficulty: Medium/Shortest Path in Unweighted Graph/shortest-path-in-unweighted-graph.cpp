class Solution {
  public:
    int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {
       // bfs method
        vector<vector<int>>adj(V);
        for(const auto e: edges){
            int u=e[0]; int v=e[1];
            adj[u].push_back(v); adj[v].push_back(u);
        }
        queue<int>q;
        q.push(src);
        // to track distance from src to dest (and also works for visited)
        vector<int>d(V,-1);
        d[src]=0;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            if(curr==dest) return d[dest];
            // go for curr neighbor
            for(const auto &neighbor:adj[curr]){
                if(d[neighbor]==-1){
                    d[neighbor]=d[curr]+1;
                    q.push(neighbor);
                }
            }
        }
        return -1;
    }
};
