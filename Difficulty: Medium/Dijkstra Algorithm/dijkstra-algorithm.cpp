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
      set<pair<int,int>>s;
      vector<int>d(V,INT_MAX);
      d[src]=0;
      s.insert({0,src});
      while(!s.empty()){
          int node = s.begin()->second;
          int wt  = s.begin()->first;
          s.erase(s.begin());
          if(wt > d[node]) continue;
          for(auto &nighbor : adj[node]){
              //have to go from node to its nighbor
              // src to node -> wt 
              // now src to nighbor -> d[node] + nighbor_wt || d[nighbor].
              int nighbor_node = nighbor.first;
              int nighbor_wt   = nighbor.second;
              if(wt+nighbor_wt < d[nighbor_node]){
                  // if d[nighbor_node] was alredy in set the erase it
                  if(d[nighbor_node]!=INT_MAX) s.erase({d[nighbor_node],nighbor_node}); 
                  
                  d[nighbor_node] = wt+nighbor_wt;
                  s.insert({d[nighbor_node],nighbor_node});
              }
          }
      }
      return d;
    }
};

// version 2 by using set 
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
      set<pair<int,int>>s;
      vector<int>d(V,INT_MAX);
      d[src]=0;
      s.insert({0,src});
      while(!s.empty()){
          int node = s.begin()->second;
          int wt  = s.begin()->first;
          s.erase(s.begin());
          if(wt > d[node]) continue;  // not necessery here
          for(auto &nighbor : adj[node]){
              //have to go from node to its nighbor
              // src to node -> wt 
              // now src to nighbor -> d[node] + nighbor_wt || d[nighbor].
              int nighbor_node = nighbor.first;
              int nighbor_wt   = nighbor.second;
              if(wt+nighbor_wt < d[nighbor_node]){
                  // if d[nighbor_node] was alredy in set the erase it
                  if(d[nighbor_node]!=INT_MAX) s.erase({d[nighbor_node],nighbor_node}); 
                  
                  d[nighbor_node] = wt+nighbor_wt;
                  s.insert({d[nighbor_node],nighbor_node});
              }
          }
      }
      return d;
    }
};
