class Solution {
  public:
    int wordLadder(vector<string> &words, string &s, string &e) {
        // traking visited - in sting use unordered_set
        unordered_set<string>visited(words.begin(),words.end());
        if(visited.find(e)==visited.end()) return 0;
        
        queue<pair<string, int>> q; 
        q.push({s, 1}); // startword should be count
        visited.erase(s); // sometime s not be in words(fine).
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word==e) return steps;
            
            // now have to travese in nighbor of word.
            // all the words with same length as word &
            // differ by just one alphabet is word's nighboring word
            // if nighbor is unvisited visit it and push in queue by incr. steps
            for(int i=0;i<word.length();i++){
                char original_char = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(visited.find(word)!=visited.end()){
                        q.push({word,steps+1});
                        visited.erase(word);
                    }
                }
                word[i]=original_char;
            }
        }
       return 0; //no path found 
    }
};