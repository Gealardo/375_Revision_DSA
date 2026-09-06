class Solution {
  public:
    vector<int> solveQueries(vector<int>& arr, vector<vector<int>>& queries, int k) {
       int n = arr.size(); 
       int blocks = ceil( sqrt(n) );
       int num_blocks = (n+(blocks-1))/blocks;
       vector<unordered_map<int,int>>box;
     
       for(int i=0;i<num_blocks;i++){
           unordered_map<int,int>freq;
           for(int j=i*blocks;j<min(n,blocks*(i+1));j++){
               freq[arr[j]]++;
           }
           box.push_back(freq);
       }
       vector<int>output;
       for(auto &query:queries){
           
             int startidx=query[0]-1 ; int startblock=(startidx/blocks);
             int endidx=query[1]-1   ; int endblock = (endidx/blocks);
             unordered_map<int,int>freq;
         
             // l,r exist in same block
             if(startblock == endblock){
                for(int i=startidx ; i<=endidx ;i++){
                    freq[arr[i]]++;
                }
             }
         
             // l and r lies in diff blocks
             else{
                
                // l to end of l's block
                for(int i=startidx ; i<((startblock+1)*blocks) ;i++){
                    freq[arr[i]]++;
                }
                // middle block
                for(int b=startblock+1 ; b<endblock ; b++){
                    for(auto &it :box[b]){
                        freq[it.first]+=it.second;
                    }
                }    
                // start of endblock to r;
                for(int i=(endblock*blocks) ; i<=endidx ;i++){
                    freq[arr[i]]++;
                }
             }
           int count=0;
           for(auto &f:freq){
               if(f.second>=k) count++;
           }
           output.push_back(count);
        }
        
       return output;
    }
};
