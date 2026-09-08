class Solution {
  public:
   void dfs(int node, vector<vector<pair<int,int>>>&adj,vector<bool>&visited,stack<int>&st){
       visited[node]=true;
       for(auto &neighbor : adj[node]){
           if(!visited[neighbor.first]){
               dfs(neighbor.first,adj,visited,st);
           }
       }
       st.push(node);
   }
    vector<int> shortestPath(int V, vector<vector<int>>& edges) {
       int e=edges.size();
       vector<vector<pair<int,int>>>adj(V);
       for(int i=0;i<e;i++){
           int u=edges[i][0];
           int v=edges[i][1];
           int wt=edges[i][2];
           adj[u].push_back({v,wt});
       }
       stack<int>st;
       vector<bool>visited(V,false);
       for(int i=0;i<V;i++){
           if(!visited[i]){
               dfs(i,adj,visited,st);
           }
       }
       // shortest distance path
       vector<int>dist(V,INT_MAX);
       int source_node = 0;
       dist[source_node]=0;
       // take out from stack one by one
       while(!st.empty()){
           int node=st.top();
           st.pop();
           if(dist[node]!=INT_MAX){
               for(auto &neighbor : adj[node]){
                   int v=neighbor.first; int wt=neighbor.second;
                   //source to node shortest distance = dist[node];
                   // node to neighbor_node  = wt;
                   // source to neighbor_node = dist[node] + wt || dist[neighbor->node];
                   if(dist[node]+wt < dist[v]){
                       dist[v]=dist[node]+wt;
                   }
               }
           }
       }
       
       for(int i=0;i<V;i++){
           if(dist[i]==INT_MAX) dist[i]=-1;
       }
      return dist; 
    }
};
