class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        int e=edges.size();
        vector<vector<int>>adj(V);
        for(auto &it:edges){
            int u=it[0]; int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
              queue<pair<int,int>>q;
              int start=i;
              q.push({start,-1});
              visited[start]=1;
              while(!q.empty()){
                  int node=q.front().first;
                  int parent=q.front().second;
                  q.pop();
                  for(auto &nighbor:adj[node]){
                      if(!visited[nighbor]){
                          q.push({nighbor,node});
                          visited[nighbor]=1;
                      }
                      else{
                          if(parent!=nighbor) return true;
                      }
                  }
              }
            }  
        }      
        return false;
    }
};