class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<int>ans;
        int row=0; int col=0;
        while(row<m && col<n){
            int sum=row+col;
            ans.push_back(mat[row][col]);
            //even
            if(sum%2==0){
               if(col==n-1) row++;
               else if(row==0){
                  col++;
               }
               else{
                  col++;
                  row--;
               }
            }
            // odd
            else {
               if(row==m-1) col++;
               else if(col==0){
                 row++;
               }
               else{
                  col--;
                  row++;
               }
            }
        }
     return ans;   
    }
};
