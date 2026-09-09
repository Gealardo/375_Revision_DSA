// version 1 by using priority queue
// Djisktra's Algorithm only applicable on +ve wt graph
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
       vector<vector<pair<int, int>>> adj(V);
      for(const auto &it :edges){
          int u = it[0]; int v=it[1]; int wt=it[2];
          adj[u].push_back({v,wt});
          adj[v].push_back({u,wt});
      }
      
      priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
      // pq=> {wt,node}; sort on the basis of wt;
      vector<int>d(V,INT_MAX);
      d[src]=0;
      pq.push({0, src});
      while(!pq.empty()){
          int node = pq.top().second;
          int wt = pq.top().first;
          pq.pop();
          if (wt > d[node]) continue; 
          for(auto &it : adj[node]){
              int nighbor = it.first;
              int nighbor_wt = it.second;
              if( wt + nighbor_wt < d[nighbor]){
                  d[nighbor] = wt+nighbor_wt;
                  pq.push({d[nighbor],nighbor});
              }
          }
      }
      return d;
    }
};