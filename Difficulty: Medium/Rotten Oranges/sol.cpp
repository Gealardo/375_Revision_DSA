class Solution {
  public:
    int orangesRotting(vector<vector<int>>& mat) {
            int n=mat.size();
            int m=mat[0].size();
            queue<pair<int,int>>q;
            int fresh=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                   if(mat[i][j]==2) q.push({i,j});
                   else if(mat[i][j]==1) fresh++;
                }
            }
            if(fresh==0) return 0;
            vector<pair<int,int>>dir={{-1,0},{1,0},{0,-1},{0,1}};
            int time=0;
            while(!q.empty() && fresh>0){
                time++;
                int size=q.size();

                for(int i=0;i<size;i++){
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
                    for(int k=0;k<4;k++){
                       int nr = row+dir[k].first;
                       int nc= col+dir[k].second;
                       if(nr>=0 && nc>=0 && nr<n && nc<m && mat[nr][nc]==1){
                           fresh--;
                           mat[nr][nc] = 2;
                           q.push({nr,nc});
                       }
                    }
                }
            }
            return (fresh==0)? time:-1;
        }
    int orangesRot(vector<vector<int>>& mat) {
        return orangesRotting(mat);
    }
};
