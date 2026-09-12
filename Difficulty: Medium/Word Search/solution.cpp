class Solution {
public:
    bool dfs(int r,int row,int c,int col,int idx,int s,vector<vector<char>>& board,string& word){
        if(r<0 || c<0 || idx<0 || r>=row || c>=col || idx>=s || board[r][c]!=word[idx] ) return false;
        if(idx==s-1) return true;
        char temp=board[r][c];
        board[r][c]='#';
        if(r-1>=0 && board[r-1][c]==word[idx+1]){
           if( dfs(r-1,row,c,col,idx+1,s,board,word)==true) return true;
        }
        if(r+1<row && board[r+1][c]==word[idx+1]){
           if( dfs(r+1,row,c,col,idx+1,s,board,word)==true) return true;
        }
        if(c-1>=0 && board[r][c-1]==word[idx+1]){
           if( dfs(r,row,c-1,col,idx+1,s,board,word)==true) return true;
        }
        if(c+1<col && board[r][c+1]==word[idx+1]){
           if( dfs(r,row,c+1,col,idx+1,s,board,word)==true) return true;
        }
        board[r][c]=temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int s=word.length();
        int n=board.size();
        int m=board[0].size();
        int idx=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[idx]){
                   if(dfs(i,n,j,m,idx,s,board,word)==true) return true;
                }
            }
        }
        return false;
    }
};
