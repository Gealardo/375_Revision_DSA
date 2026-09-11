
   string printSequence(string S) {
      int n=S.length();
      vector<string> key = {
                "2", "22", "222", 
                "3", "33", "333", 
                "4", "44", "444", 
                "5", "55", "555", 
                "6", "66", "666", 
                "7", "77", "777", "7777", 
                "8", "88", "888", 
                "9", "99", "999", "9999"
            };
      string num="";
      for(int i=0;i<n;i++){
          if(S[i]==' ') num+="0";
          else{
              int idx = S[i]-'A';
              num+=key[idx];
          }
      }
      return num;
   }  