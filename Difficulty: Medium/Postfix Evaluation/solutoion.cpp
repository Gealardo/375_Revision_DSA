class Solution {
  public:
    int evaluatePostfix(vector<string>& arr) {
       int n=arr.size();
       stack<int>s;
        for(int i=0;i<n;i++){
            
            if (arr[i] == "+" || arr[i] == "-" || arr[i] == "*" || arr[i] == "/" || arr[i] == "^"){
               int a,b;  
               b = s.top(); s.pop();
               a = s.top(); s.pop();
               if(arr[i]=="+") s.push(a+b);
               else if(arr[i]=="-") s.push(a-b);
               else if(arr[i]=="*") s.push(a*b);
               else if(arr[i] == "/") s.push(floor(static_cast<double>(a) / b)); 
               else s.push(pow(a,b));
            } 
            else s.push(stoi(arr[i]));
        }
     return s.top();    
    }
};
