class Solution {
  public:
    struct lemda{
      bool operator()(string&a,string&b){
          return (a+b)>(b+a);
      }  
    };
    string findLargest(vector<int> &arr) {
        int n=arr.size();
        vector<string>numbers;
        for(const auto &num : arr){
            numbers.push_back(to_string(num));
        }
        if(numbers[0]=="0") return "0";
        sort(numbers.begin(),numbers.end(),lemda());
        string ans="";
        for(auto &nu : numbers){
            ans+=nu;
        }
        return ans;
    }
};
