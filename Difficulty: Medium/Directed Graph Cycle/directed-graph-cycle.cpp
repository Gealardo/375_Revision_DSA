class Solution {
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // adjecency list.
        int e=edges.size();
        vector<vector<int>>adj(V);
        for(const auto &it : edges){
            adj[it[0]].push_back(it[1]);
        }
        //calculate indegree.
        vector<int>in(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                in[adj[i][j]]++;
            }
        }
        // indegree 0 node.
        vector<int>topo;
        queue<int>q;
        for(int i=0;i<V;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topo.push_back(node);
            for(auto &nighbor:adj[node]){
                in[nighbor]--;
                if(in[nighbor]==0) q.push(nighbor);
            }
        }
        int n=topo.size();
        return V!=n;
    }
};